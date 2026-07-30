#include <bits/stdc++.h>
using namespace std;

int main(){
    
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, c;
    cin >> n >> c;
    vector<long long> predios(n);
    for(int i=0;i<n;i++){
        cin >> predios[i];
    }
    vector<long long> incrementos(n, 0);
    for(int i=0;i<c;i++){
        long long aux;
        int mes;
        cin >> mes >> aux;
        incrementos[mes-1] += aux;
    }

    long long conta = 0;
    for(int i=n-1;i>=0;i--){
        conta+=incrementos[i];
        predios[i] += conta;
    }

    // for(int i=0;i<n;i++) cout << incrementos[i] << " ";
    // cout << endl;

    // vector<long long> lds(n,1);
    // for(int i=1;i<n;i++){
    //     if(predios[i] < predios[i-1]) lds[i] = lds[i-1] + 1LL;
    // }

    vector<long long> tams(n);
    tams[0] = 1;
    stack<long long> pilha;
    pilha.push(predios[0]);
    for(int i=1;i<n;i++){
        while(!pilha.empty() && predios[i] >= pilha.top()){
            pilha.pop();
        }
        pilha.push(predios[i]);
        tams[i] = pilha.size();
    }

    // for(int i=0;i<n;i++) cout << predios[i] << " ";
    // cout << endl;

    for(int i=1;i<n;i++){
        cout << tams[i-1] << endl;
    }


    return 0;
}