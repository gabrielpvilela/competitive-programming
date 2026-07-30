#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long int memo[2020];
int l;
long long int solve1(int v, vector<vector<int>> &tree){
    if(memo[v] != -1)
        return memo[v];
    if(v > l)
        return memo[v] = 1;

    long long int ans = 0;
    for(auto u: tree[v]){
        ans = (ans+solve1(u, tree))%mod;
    }
    return memo[v] = ans;
    
}

int main() {
    memset(memo, -1, sizeof memo);

    int n;
    cin >> n >> l;

    vector<vector<int>> v(n+1, vector<int>());
    for(int i = 1; i <= l; i++){
        int k;
        cin >> k;
        while(k--){
            int f;
            cin >> f;
            v[i].push_back(f);
        }
    }
    long long int res1 = solve1(1, v);
    int res2 = 0;

    vector<int> vis(n+1, 0);
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int vv = q.front();
        q.pop();
        for(auto u: v[vv]){
            if(!vis[u]){
                q.push(u);
                if(u > l)
                    res2++;
                vis[u] = 1;
            }
        }
    }
    cout << res1 << ' ' << res2 << endl;

    return 0;
}