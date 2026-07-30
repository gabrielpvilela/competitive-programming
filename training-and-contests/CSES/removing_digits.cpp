#include<bits/stdc++.h>
using namespace std;

int memo[1000001];

int dp(int num){
    if(num < 0) return 1e7;

    if(memo[num] != -1) return memo[num];
    if(num == 0) return memo[num] = 0;
    int ans = 1e7;
    if(num%10!=0)ans = min(ans,dp(num - num%10)+1);
    int m = 10;
    while(num%m != num){
        if(m>num) break;
        //cout << "travout" << endl;
        if(num%(m*10)/m != 0)ans = min(ans, dp(num - num%(m*10)/m)+1);
        m*= 10;
    }
    //ans = min(ans, dp(num/m));
    return memo[num] = ans;
}

int main(){

    int n;
    cin >> n;
    memset(memo, -1, sizeof(memo));
    cout << dp(n) << endl;

    return 0;
}