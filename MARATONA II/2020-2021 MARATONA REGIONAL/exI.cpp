#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
vector<int> filhos[100001];
// int folhas[100001];
long long memo[100001][2];
long long solve(int v, int k){

    if(memo[v][k] != -1) return memo[v][k];
    long long ans = 0;
    if(filhos[v].size() == 0){
        // folhas[v]++;
        return memo[v][k] = 1;
    }
    vector<long long> suffix(filhos[v].size(), 1), prefix(filhos[v].size(), 1);
    prefix[0] = solve(filhos[v][0],0);
    // folhas[v] = folhas[filhos[v][0]];

    for(int i=1;i<filhos[v].size();i++){
        prefix[i] = (solve(filhos[v][i], 0) * prefix[i-1]) % MOD;
        // folhas[v] += folhas[filhos[v][i]];
    }

    suffix[filhos[v].size() - 1] = solve(filhos[v][filhos[v].size() - 1], 0);
    for(int i = filhos[v].size() - 2; i>=0; i--){
        suffix[i] = (solve(filhos[v][i], 0) * suffix[i+1]) % MOD;
    }

    if(k==0)ans = suffix[0];
    for(int i=0;i<filhos[v].size();i++){
        long long mult = solve(filhos[v][i], 1);
        if(i>0) mult = (mult * prefix[i-1])%MOD;
        if(i<filhos[v].size() - 1) mult = (mult * suffix[i+1])%MOD;
        ans += mult;
        ans %= MOD;
    }
    return memo[v][k] = ans;
}

int main(){

    int n;
    cin >> n;
    // memset(folhas, 0, sizeof(folhas));
    memset(memo, -1, sizeof(memo));
    for(int i=2;i<=n;i++){
        int m;
        cin >> m;
        filhos[m].push_back(i);
    }

    cout << solve(1, 0) << endl;
    // for(int i=0;i<n;i++){
    //     cout << memo[i][0] << endl;
    //     cout << memo[i][1] << endl;
    // }


    return 0;
}