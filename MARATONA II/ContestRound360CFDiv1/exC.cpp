#include<bits/stdc++.h>
using namespace std;

//COMPLETO

bool dp[501][501][501]; //i, j, k;

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> c(n+1);
    for(int i=1;i<=n;i++){
        cin >> c[i];
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = true;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=500;j++){
            for(int k=0;k<=500;k++){
                dp[i][j][k] |= (dp[i-1][j][k]);
                if(j >= c[i]) dp[i][j][k] |= dp[i-1][j-c[i]][k];
                if(j>= c[i] && k >= c[i]) dp[i][j][k] |= dp[i-1][j-c[i]][k-c[i]];
            }
        }
    }
    int conta = 0;
    vector<int> ans;
    for(int i=0;i<501;i++){
        if(dp[n][k][i]){
            conta++;
            ans.push_back(i);
        }
    }
    cout << conta << endl;
    for(int i=0;i<ans.size();i++){
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}