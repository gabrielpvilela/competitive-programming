#include<bits/stdc++.h>
using namespace std;
const long long NMAX = 19;
long long memo[1<<NMAX][NMAX];
long long solve(long long mask, long long v, vector<vector<long long>>& adj, long long s){
    if(memo[mask][v]!=-1) return memo[mask][v];
    long long ans = 0;
    for(auto u: adj[v]){
        //if(u == pai) continue;
        if(u<s) continue;
        if(u == s && __builtin_popcount(mask) >= 3) ans+=1;
        else if(!((mask >> u) & 1))ans += solve(mask ^ (1 << u), u, adj,s);
    }

    return memo[mask][v] = ans;
}

int main(){

    long long n, m;

    cin >> n >> m;
    vector<vector<long long>> adj(n);
    for(long long i=0;i<m;i++){
        long long a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(memo, -1, sizeof memo);
    long long ans = 0;
    for(long long i=0;i<n;i++){
        ans += solve(1<<i, i, adj, i);
    }

    cout << ans/2 << endl;

    return 0;
}