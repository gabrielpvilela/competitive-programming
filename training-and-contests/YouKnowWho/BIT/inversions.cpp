#include<bits/stdc++.h>
using namespace std;

const int NMAX = 112345;

int bit[NMAX];

void update_BIT(int tam, int index, int valor){
    index++;
    while(index <= tam){
        bit[index] += valor;
        index += index & (-index);
    }
}

void buildBIT(){
    int i;
    memset(bit, 0, sizeof(bit));
    // for(int i=0;i<tam;i++){
    //     update_BIT(tam, i, vet[i]);
    // }
}

int queryBIT(int index){
    int soma = 0;
    while(index > 0){
        soma += bit[index];
        index -= index & (-index);
    }
    return soma;
}

int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> ans;
    buildBIT();
    for(int i=0;i<n;i++){
        int p;
        cin >> p;
        p--;
        update_BIT(n+1, p, 1);
        ans.push_back(queryBIT(n) - queryBIT(p+1));
    }
    for(int i=0;i<n;i++){
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}