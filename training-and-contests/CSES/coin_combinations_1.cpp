#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, x;
    int m =1e9 + 7;
    cin >> n >> x;
    vector<int> c(n+1);
    long long dp[x+1];
    for(int i=1;i<=n;i++){
        cin >> c[i];
    }
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        dp[i] = 0;
        for(int j=1;j<=n;j++){
            if(i>=c[j]){
                dp[i] += dp[i-c[j]];
                dp[i]%=m;
            }
        }
    }
    cout << dp[x] << endl;

    return 0;
}