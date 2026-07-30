#include<bits/stdc++.h>
using namespace std;
int main(){

    string t, s;
    cin >> t >> s;
    bool deuBom = false;
    for(int i=0;i<=(int)t.size()-(int)s.size();i++){
        bool deuRuim = false;
        for(int j=0;j<s.size();j++){
            if(s[j] != t[i+j] && t[i+j] != '?'){
                deuRuim = true;
                break;
            }
        }
        if(!deuRuim){
            deuBom = true;
            break;
        }
    }
    if(deuBom) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}