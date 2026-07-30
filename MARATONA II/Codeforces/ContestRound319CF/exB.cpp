#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];

    int memo[1001];
    memset(memo, 0, sizeof memo);
    int quando[1001];
    memset(quando, -1, sizeof quando);
    for(int i=0;i<n;i++){
        if(!memo[nums[i]%m])quando[nums[i]%m] = i;
        memo[nums[i]%m] = 1;
        for(int j=0;j<m;j++){
            if(!memo[j] && memo[(j - (nums[i]%m) + m)%m] && quando[(j - (nums[i]%m) + m)%m] != i){
                memo[j] = 1;
                quando[j] = i;
            }
            if(memo[0]) break;
        }
        if(memo[0]) break;
    }
    //for(int i=0;i<m;i++) cout << memo[i] <<" ";
    if(memo[0]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}