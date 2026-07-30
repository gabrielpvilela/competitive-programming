#include<bits/stdc++.h>
using namespace std;

int memo[1 << 20][20];
const int mod = 1e9 + 7;
int solve(int mask, int n, vector<vector<int>>& adj){

    if(memo[mask][n] != -1) return memo[mask][n];
    if(!mask && !n) return 1;
    else if(!mask) return 0;
    int ans = 0;
    for(auto u : adj[n]){
        if((mask >> u) & 1)ans = (ans + solve(mask ^ (1 << u), u, adj)) % mod;
    }
    return memo[mask][n] = ans;
}

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a>> b;
        a--; b--;
        adj[b].push_back(a);
    }
    int tot = 0;
    memset(memo, -1, sizeof memo);
    cout << solve((1 << (n-1)) - 1, n-1, adj) << endl;


    return 0;
}