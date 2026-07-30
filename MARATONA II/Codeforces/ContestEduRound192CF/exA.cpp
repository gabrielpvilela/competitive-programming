#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        bool certo = false, certo3 = false, certo2 = false;
        for(int i=0;i<k;i++){
            int n;
            cin >> n;
            if(n >= 3) certo3 = true;
            if(n == 2){
                if(certo2) certo = true;
                certo2 = true;
            }
        }
        if(certo || certo3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    //4 min

    return 0;
}