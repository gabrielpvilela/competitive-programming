#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    long long n;
    cin >> n;
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin >> nums[i];
    }   

    long long ans = -1;
    while(nums.size() > 1){
        vector<long long> aux;
        for(long long i=0;i<nums.size();i+=2){
            if(i != (long long)nums.size()-1){
                ans = max(ans, abs(nums[i] - nums[i+1]));
                aux.push_back(max(nums[i], nums[i+1]));
            }else{
                aux.push_back(nums[i]);
            }
    
        }
        nums = aux;
    }
    cout << ans << endl;
    return 0;
}