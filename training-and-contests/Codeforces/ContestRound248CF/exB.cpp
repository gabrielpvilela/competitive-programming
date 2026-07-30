#include<bits/stdc++.h>
using namespace std;

int main(){

    long long int t = 1;
    
    while(t--){
        long long int n;
        cin >> n;
        vector<long long int> nums(n+1);
        for(long long int i=1;i<=n;i++) cin >> nums[i];
        nums[0] = 0;
        long long int q;
        cin >> q;
        vector<long long int> pref(n+1), ord(n+1), ordPref(n+1);
        ord = nums;
        sort(ord.begin(), ord.end());
        ordPref[0] = ord[0];
        pref[0] = nums[0];
        for(long long int i=1;i<=n;i++){
            ordPref[i] = ordPref[i-1] + ord[i];
            pref[i] = pref[i-1] + nums[i];
        }

        for(long long int i=0;i<q;i++){

            long long int op, l, r;
            cin >> op >> l >> r;
            l--;
            if(op==1){

                cout << pref[r] - pref[l] << endl;
            }else cout << ordPref[r] - ordPref[l] << endl;
        }
    }


    return 0;
}