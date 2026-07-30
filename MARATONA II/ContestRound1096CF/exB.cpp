#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int conta = 0;
        for(int i=0;i<n;i++){
            if(s[i] == ')') conta++;
            else conta--;
        }
        if(conta!=0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}