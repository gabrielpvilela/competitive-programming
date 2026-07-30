#include<bits/stdc++.h>
using namespace std;

int main(){


    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);

        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        bool first = false;
        int mai = -1;
        int conta = -1;
        for(int i=0;i<n;i++){
            if(!i){
                if(nums[i] != nums[i+1]){
                    if(!first) first = true;
                    else {mai = nums[i]; break;}
                }
            }else if(i == n-1){
                if(nums[i] != nums[i-1]){
                    if(!first) first = true;
                    else {mai = nums[i-1]; break;}
                }
            }else{
                if(nums[i] != nums[i-1] && nums[i] != nums[i+1]){
                    if(!first) first = true;
                    else {mai = nums[i-1]; break;}
                }
            }
            if(nums[i] == conta+1) conta = nums[i];
        }
        if(mai == -1) mai = nums[n-1];
        cout << min(mai+1, conta+1) << endl;
    }
    return 0;
}