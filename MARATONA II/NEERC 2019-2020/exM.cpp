#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        long long ans = 0;
        for(int i=n-1;i>=0;i--){
            map<int,int> cont;
            for(int j=i-1;j>=0;j--){
                if(cont.find(nums[j]) != cont.end()){
                    ans += cont[nums[j]];
                    // cout << nums[j] + nums[j] - nums[i] << endl; 
                }
                cont[nums[j] + (nums[j]-nums[i])]++;
            }
        }
        cout << ans << endl;
    }


    return 0;
}