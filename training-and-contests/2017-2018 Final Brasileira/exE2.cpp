#include<bits/stdc++.h>
using namespace std;

int memo[1001][1001];
string s, ans;
int N;
bool solve(int pos, int mod){

    if(pos >= s.length()){
        return mod == 0;
    }
    if(memo[pos][mod]!=-1){
        return memo[pos][mod];
    }

    if(s[pos] != '?'){
        int v = s[pos] - '0';
        if(solve(pos+1, ((mod*10 + v)%N))){
            ans[pos] = s[pos];
            return memo[pos][mod] = true;
        }else{
            return memo[pos][mod] = false;
        }
    }
    int ini = pos==0? 1: 0;
    for(int i=ini;i<=9;i++){
        // int v = s[pos] - '0';
        if(solve(pos+1, (mod*10 + i)%N)){
            ans[pos] = i+'0';
            return memo[pos][mod] = true;
        }
    }
    return memo[pos][mod] = false;
}

int main(){

    cin >> s >> N;
    for(int i=0;i<s.size();i++) ans+=" ";
    memset(memo, -1, sizeof(memo));
    
    if(!solve(0,0)){
        cout << "*" << endl;
        return 0;
    } 
    cout << ans << endl;

    return 0;
}