#include<bits/stdc++.h>
using namespace std;

int solve(string s, int l, int r){


    for(int i=0;i<s.size();i++){
        if(l && s[i] == '('){
            s[i] = '.';
            l--;
        }
    }
    for(int i=(int)s.size()-1;i>=0;i--){
        if(r && s[i] == ')'){
            s[i] = '.';
            r--;
        }
    }
    int conta = 0;
    int ans = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '(') conta++;
        else if(s[i] == ')' && conta){
            conta--;
            ans++;
        } 
    }
    return ans;
}

int main(){

    long long t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = INT32_MAX, l = -1;
        vector<int> pre(n, 0);
        for(int i=0;i<=k;i++){
            int resp = solve(s, i, k-i);
            if(resp < ans) l = i;

            ans = min(ans, resp);
        }
        string res;

        for(int i=0;i<n;i++) res+='0';
        if(l==-1){
            cout << res << endl;
            continue;
        }
        int r = k - l;
        for(int i=0;i<s.size();i++){
            if(l && s[i] == '('){
                res[i] = '1';
                l--;
            }
        }
        for(int i=(int)s.size()-1;i>=0;i--){
            if(r && s[i] == ')'){
                res[i] = '1';
                r--;
            }
        }
        cout << res << endl;
    }

    return 0;
}