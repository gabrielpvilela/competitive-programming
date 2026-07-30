#include<bits/stdc++.h>
using namespace std;
int memo[102][4];
int solve(int n, int ult, vector<int>& dias){
    if(n == 0) return 0;
    if(memo[n][ult] != -1) return memo[n][ult];

    int ativ = dias[n];
    int ans = 202;
    if(ativ == 3) {
        if(ult != 1)ans = min(ans, solve(n-1, 1, dias));
        if(ult != 2)ans = min(ans, solve(n-1, 2, dias));
        ans = min(solve(n-1, 0, dias) + 1, ans);
    }
    else if(ativ == 2){
        if(ativ != ult) ans = min(ans, solve(n-1, 2, dias));
        ans = min(solve(n-1, 0, dias) + 1, ans); 
    }else if(ativ == 1){
        if(ativ != ult) ans = min(ans, solve(n-1, 1, dias));
        ans = min(solve(n-1, 0, dias) + 1, ans); 
    }else{
        ans = min(solve(n-1, 0, dias) + 1, ans);
    }
    return memo[n][ult] = ans;

}

int main(){

    int n;
    cin >> n;
    vector<int> dias(n+1);
    for(int i=1;i<=n;i++) cin >> dias[i];


    memset(memo, -1, sizeof memo);
    for(int i=0;i<4;i++) memo[0][i] = 0;

    int INF = 500;
    int ans = INF;
    for(int i=0;i<3;i++){
        ans= min(ans, solve(n, i, dias));
    }

    cout << ans << endl;

    return 0;
}