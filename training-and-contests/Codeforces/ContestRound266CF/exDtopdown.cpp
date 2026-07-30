#include<bits/stdc++.h>
using namespace std;

const int NMAX = 2001;
const int MOD = 1e9 + 7;

long long memo[NMAX][NMAX];
int n, h;
vector<int> nums(NMAX);

long long solve(int pos,long long opened){

    if(pos == n){
        return opened ? 0LL : 1LL;
    }
    if(memo[pos][opened]!=-1) return memo[pos][opened];

    long long ans = 0;
    if(opened+nums[pos] == h){
        ans = (ans+solve(pos+1, opened))%MOD;
        if(opened) ans = (ans + solve(pos+1, opened-1)*opened)%MOD;
    }       
    if(opened+nums[pos] == h-1){
        ans = (ans + solve(pos+1, opened+1))%MOD;
        ans = (ans + solve(pos+1, opened)*(opened+1))%MOD;
    }

    return memo[pos][opened] = ans%MOD;

}

int main(){

    memset(memo, -1, sizeof memo);
    cin >> n >> h;
    for(int i=0;i<n;i++) cin >> nums[i];
    cout << solve(0, 0LL) << endl;
    return 0;
}