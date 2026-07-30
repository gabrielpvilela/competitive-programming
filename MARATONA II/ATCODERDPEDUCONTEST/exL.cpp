#include<bits/stdc++.h>
using namespace std;
const int NMAX = 3001;
long long memo[NMAX][NMAX]; //l e r

long long solve(int l, int r, vector<int>& nums){
    if(l == r){
        return memo[l][r] = nums[l];
    }
    if(memo[l][r] != -1){
        return memo[l][r];
    }
    long long ans = 0;

    ans = max(nums[l] - solve(l+1, r, nums), nums[r] - solve(l, r-1, nums));
    return memo[l][r] = ans;
}

int main(){

    int n;
    cin >> n;

    vector<int> nums(n);
    memset(memo, -1, sizeof(memo));
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    cout << solve(0, n-1, nums) << endl;

    return 0;
}