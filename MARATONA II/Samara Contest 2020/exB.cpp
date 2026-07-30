#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, t;
    cin >> n >> t;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    int melhorDir = 0;
    int pos = -1;
    for(int i=0;i<n;i++){
        if(nums[i] <= 0) pos = i;
        if(nums[i] > t) break;
        if(nums[i] >= 0) melhorDir++;
    }
    int melhorEsq = 0;
    for(int i =0;i<n;i++){
        if(nums[i] > 0) break;
        if(abs(nums[i]) <= t){
            melhorEsq = abs(i-t) + 1;
            break;
        }
    }
    int ans = max(melhorDir, melhorEsq);
    vector<int> pontos(n, 0);
    for(int i=0;i<n;i++){
        if(nums[i] == 0) pontos[i] = 1;
        else{
            if(nums[i] > 0 && i) pontos[i] = pontos[i-1] + 1;
            else if(nums[i] > 0) pontos[i] = 1; 
        }
    }
    for(int i=n-1;i>=0;i--){
        if(nums[i] == 0) nums[i] = 1;
        else{
            if(nums[i] < 0 && i!=n-1 && nums[i]*nums[i+1] < 0) pontos[i] = 1;
            else if(nums[i] < 0 && i!=n-1) pontos[i] = pontos[i+1] + 1;
            else if(nums[i] > 0) pontos[i] = 1; 
        }
    }


    for(int i=0;i<n;i++){
        int p = pontos[i];
        int te = t - abs(nums[i]);
        if() 
    }



    return 0;
}