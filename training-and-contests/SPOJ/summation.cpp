#include<bits/stdc++.h>
using namespace std;
//accepted
int main(){

    vector<long long> pow2(1001);
    pow2[0] = 1;
    const int mod = 100000007;
    for(int i=1;i<1001;i++){
        pow2[i] = pow2[i-1] * 2LL % mod;
    }
    int t;
    cin >> t;
    int aux = t;
    while(aux--){
        int n;
        cin >> n;
        vector<int> nums(n);
        long long ans = 0;
        for(int i=0;i<n;i++) cin >> nums[i];
        for(int i=0;i<n;i++){
            ans = (ans + pow2[n-1] * nums[i])%mod;
        }
        cout << "Case " << t-aux << ": " << ans << endl;
    }


    return 0;
}