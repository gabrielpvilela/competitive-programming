#include<bits/stdc++.h>
using namespace std;
int main(){

    long long int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        long long ans = n;
        vector<bool> correc(n, false);
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        for(int i=0;i<n;i++){
            if(i && i<n-1){
                if(nums[i] < nums[i-1] + nums[i+1]) correc[i] = true;
            }
        }
        long long pa = 2; 
        for(int i=1;i<n-1;i++){
            if(correc[i]){
                ans+=(pa/2);
                pa++;
            }else{
                pa = 2;
            }
        }
        cout << ans << endl;
    }

    return 0;
}