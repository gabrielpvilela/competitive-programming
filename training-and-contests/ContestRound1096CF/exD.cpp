#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(2*n);
        int pos1 = -1, pos2 = -1;
        for(int i=0;i<2*n;i++){
            cin >> nums[i];
            if(nums[i] == 0 && pos1 == -1) pos1 = i;
            else if(nums[i] == 0 && pos1 != -1) pos2 = i;
        }
        int melhor1, melhor2, melhor3;
        int aumento = 1;
        set<int> mex1;
        mex1.insert(0);
        while(pos1 - aumento >= 0 && pos1+aumento < n*2 && nums[pos1-aumento] == nums[pos1+aumento]){
            mex1.insert(nums[pos1-aumento]);
            aumento++;
        }
        melhor1 = 0;
        for(auto m : mex1){
            if(m==melhor1) melhor1++;
            else break;
        }

        aumento = 1;
        set<int> mex2;
        mex2.insert(0);
        while(pos2 - aumento >= 0 && pos2+aumento < n*2 && nums[pos2-aumento] == nums[pos2+aumento]){
            mex2.insert(nums[pos2-aumento]);
            aumento++;
        }
        melhor2 = 0;
        for(auto m : mex2){
            if(m==melhor2) melhor2++;
            else break;
        }
        aumento = (pos2 - pos1)/2;
        set<int>mex3;
        while(pos2 - aumento >= 0 && pos2 - aumento < n*2 && pos1+aumento < n*2 && pos1+aumento >=0 && nums[pos2-aumento] == nums[pos1+aumento]){
            mex3.insert(nums[pos2-aumento]);
            // cout << pos1 + aumento << endl;
            // cout << pos2 - aumento << endl;
            aumento--;
        } 
        melhor3 = 0;
        for(auto m : mex3){
            if(m==melhor3) melhor3++;
            else break;
        }
        cout << max(max(melhor1, melhor2), melhor3) << endl;
    }

    return 0;
}