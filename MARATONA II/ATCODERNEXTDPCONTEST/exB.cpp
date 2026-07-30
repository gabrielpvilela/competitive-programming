#include<bits/stdc++.h>
using namespace std;

#define mod 998244353

long long solve(vector<vector<int>>& de, vector<long long>& memo, int v){
    if(memo[v] != -1) return memo[v];
    if(v == 1) return memo[v] = 1;
    long long ans = 0;
    for(auto u :de[v]){
        ans = (solve(de, memo, u) + ans)%mod; 
    }

    return memo[v] = ans;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> deOndeVem(n+1);
        for(int i=0;i<m;i++){
            int x, y;
            cin >> x >>y;
            deOndeVem[y].push_back(x);
        }
        vector<long long> memo(n+1, -1);
        cout << solve(deOndeVem, memo, n) << endl;
    }

    return 0;
}