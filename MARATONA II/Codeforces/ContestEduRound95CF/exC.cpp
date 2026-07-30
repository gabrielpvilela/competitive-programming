#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& m, vector<int>& memo){
    
    if(n >= m.size()) return 0;
    if(memo[n] != -1) return memo[n];
    int ans = 0;
    int passosUm = 2;
    if(n+passosUm < m.size()){
        if(m[n+passosUm]) passosUm++;
    }
    int passosDois = 3;
    if(n+passosDois < m.size()){
        if(m[n+passosDois]) passosDois++;
    }

    ans = solve(n+passosUm, m, memo) + m[n];
    if(n < m.size()-1) ans = min(ans, solve(n+passosDois, m, memo) + m[n] + m[n+1]);

    return memo[n] = ans;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> monstros(n);
        for(int i=0;i<n;i++) cin >> monstros[i];
        vector<int> memo(n, -1);
        cout << solve(0, monstros, memo) << endl;
    }


    return 0;
}