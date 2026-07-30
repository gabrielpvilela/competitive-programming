#include<bits/stdc++.h>
using namespace std;

set<string> ans;
string s;

void solve(int sobraNums, string monta, int pos){

    if(sobraNums < 0) return;
    if(monta.size() == 11 && monta[1] != '0'){
        ans.insert(monta);
    }
    if(monta.size() == 0){
        solve(sobraNums-1, monta+'1', pos);
        if(pos < s.size() && s[pos] == '1'){
            solve(sobraNums, monta+'1', pos+1);
        }
    }
    else if(monta.size() == 2){
        solve(sobraNums-1, monta+'9', pos);
        if(pos < s.size() && s[pos] == '9'){
            solve(sobraNums, monta+'9', pos+1);
        }
    }else{
        solve(sobraNums-1, monta+'1', pos);
        solve(sobraNums-1, monta+'9', pos);
        if(pos < s.size()) solve(sobraNums, monta+s[pos], pos+1);
    }

}

int main(){

    
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> s;
    if(s.size() > 11){
        cout << "0" << endl;
    }else{
        solve(11 - s.size(), "", 0);
        cout << ans.size() << endl;
        for(auto st : ans){
            cout << st << endl;
        }
    }


    return 0;
}