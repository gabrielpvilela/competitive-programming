#include<bits/stdc++.h>
using namespace std;
int main(){

    int n, x;
    cin >> n >> x;
    vector<int> c(n+1);
    for(int i=1;i<=n;i++){
        cin >> c[i];
    }
    int INF = 1e7;
    //int INF = INT32_MAX;
    int dp[x+1];
    dp[0] = 0;
    for(int i=1;i<=x;i++){
        dp[i] = INF;
        for(int j=1;j<=n;j++){
            if(i>=c[j])dp[i] = min(dp[i], dp[i-c[j]]+1);
        }
    }
    if(dp[x] == INF) cout << "-1" <<endl;
    else cout << dp[x] << endl;

    return 0;
}