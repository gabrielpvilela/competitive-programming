#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> vet(n);

    for(int i = 0; i < n; i++) {
        if(s[i] == 'C') {
            vet[i] = 0;
        }
        else if(s[i] == 'E') {
            vet[i] = -1;
        }
        else vet[i] = 1;
    }

    int pos = 0;
    int conta = 0;
    for(int i = 0; i < n; i++) {
        if(pos == vet[i] || pos + 1 == vet[i] || pos - 1 == vet[i]) {
            pos = vet[i];
            conta++;
        }
        else {
            pos = 0;
        }
    }

    cout << conta << endl;

    return 0;
}