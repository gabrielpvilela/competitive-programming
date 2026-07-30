#include <bits/stdc++.h>
using namespace std;

int main() {

    string bolo;
    cin >> bolo;
    long long s;
    cin >> s;
    long long auxContaP = 0;
    for(int i =0;i<s;i++){
        if(bolo[bolo.size()-1-i] == 'E') break;
        auxContaP++;
        auxContaP = min(s, auxContaP);
    }

    long long total = 0;
    for(int i=0;i<bolo.size();i++){
        if(bolo[i] == 'P'){
            auxContaP = min(s, auxContaP+1);
            total+=auxContaP;
        }
        else auxContaP = 0;
    }

    long long ans = (bolo.size() * s) - total;
    cout << ans << endl;

    return 0;
}