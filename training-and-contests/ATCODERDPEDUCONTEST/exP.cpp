#include<bits/stdc++.h>
using namespace std;
const int NMAX = 1e5 + 1;
const int MOD = 1e9 + 7;
long long memo[NMAX][2]; //0 : branco, 1 : preto;
vector<vector<int>> adj(NMAX);
long long solve(int v, int cor, int pai = -1){

    if(memo[v][cor] != -1){
        return memo[v][cor];
    }
    long long ansB = 1;

    for(auto u : adj[v]){
        if(u == pai) continue;
        ansB = ansB * solve(u, 0, v) % MOD;
    }
    long long ansP = 0;
    if(!cor){
        ansP = 1;
        for(auto u : adj[v]){
            if(u == pai) continue;
            ansP = ansP * solve(u, 1, v) % MOD;
        }    
    }

    return memo[v][cor] = (ansB + ansP)%MOD;
}

int main(){

    memset(memo, -1, sizeof memo);
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << solve(0, 0) << endl;

    return 0;
}