#include<bits/stdc++.h>
using namespace std;
const int NMAX = 21;
int memo[1<<NMAX][NMAX];
int n;
const int m = 1e9 + 7;
int solve(int mask, int pos, vector<vector<int>>& p){

    if(pos == n){
        return 1;
    }
    if(memo[mask][pos] != -1){
        return memo[mask][pos];
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        if(p[pos][i] && !((mask >> i) & 1)) ans = (ans + solve((mask ^ (1 << i)), pos+1, p)) %m;
    }
    return memo[mask][pos] = ans;
}

int main(){


    cin >> n;
    memset(memo, -1, sizeof memo);
    vector<vector<int>> pessoas(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> pessoas[i][j];
        }
    }

    cout << solve(0, 0, pessoas) << endl;


    return 0;
}