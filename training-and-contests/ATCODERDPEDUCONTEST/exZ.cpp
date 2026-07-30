#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, c;
    cin >> n >> c;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin >> h[i];
    }

    // dp[i] = dp[j] + (h[j] - h[i])*(h[j] - h[i]) + C;
    // dp[i] = dp[j] + h[j]² - 2h[i]h[j] + h[i]² + C;
    // dp[i] = (h[i]² - 2h[j] * h[i]) + (dp[j] + h[j]² + C); 
    // h[i] = x, h[j] = b, dp[j] = d;
    // dp[i] = (x² - 2a * x + (d + b² + c));

    return 0;
}