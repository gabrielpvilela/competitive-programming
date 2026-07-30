#include<bits/stdc++.h>
using namespace std;
int N, K;
bool solve(int meio, vector<pair<int,int>>& zeros, vector<pair<int,int>>& uns){
    pair<int,int> menorUm = {INT32_MAX, 1};
    int conta = N-meio+1; //5, 4, 3
    for(int i=uns.size()-1; i>max(int(uns.size()-1-meio), -1); i--){
        if(menorUm.first > uns[i].first+conta)menorUm = {uns[i].first+conta, uns[i].second};//talvez mudar pra menor igual por causa do indice
        conta++;
    }
    int tam = zeros.size();
    int maiorZero = -1;
    int diff = max(0, K - meio);
    for(int i=0;i<zeros.size()-diff;i++){
        maiorZero = max(maiorZero, zeros[i].first+tam--);
        if(maiorZero > menorUm.first || (maiorZero == menorUm.first && zeros[i].second > menorUm.second)) return false;
    }

    return true;

}

int main(){

    int n, k;
    cin >> n >> k;
    N = n;
    vector<pair<int,int>> zeros, uns;//numero, -indice
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        int total = 0;
        for(int j=0;j<4;j++){
            int aux;
            cin >> aux;
            total += aux;
        }
        if(x) uns.push_back({total, -i});
        else zeros.push_back({total, -i});
    }
    if(n==k){
        cout << uns.size() << endl;
        return 0;
    }
    sort(zeros.begin(), zeros.end());
    sort(uns.begin(), uns.end());

    int remov = k - uns.size();
    if(remov > 0){
        k-=remov;
        while(remov--) zeros.pop_back();
    }
    K=k;
    //size dos zeros, vai ser ate qual numero de 1..size a nota deles vai, size dos uns vai ser ate qual numero de max..size ele vai

    int l = 0, r = min(k, int(uns.size()));
    int meio;
    int ans = -1;
    while(l<=r){
        meio = (l+r)/2;

        if(solve(meio, zeros, uns)){
            ans = meio;
            l = meio + 1;
        }else{
            r = meio - 1;
        }
    }

    cout << ans << endl;

    return 0;
}