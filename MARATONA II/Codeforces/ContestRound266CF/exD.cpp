#include<bits/stdc++.h>
using namespace std;

const int NMAX = 2001;
int n, h;
const int MOD = 1e9 + 7;
long long memo[NMAX][NMAX]; //memo[i][opened];
vector<int> nums(NMAX);

long long solve(int pos, int opened){

    if(pos < 0 && !opened){
        return 1;
    }else if(pos < 0){
        return 0;
    }
    if(memo[pos][opened] != -1){
        return memo[pos][opened];
    }
    long long ans = 0;
    if((nums[pos] + opened) == h){
        //n faz nada
        ans = (ans + solve(pos - 1, opened))%MOD;
        //abre
        ans = (ans + solve(pos - 1, opened - 1)) % MOD;
    }   
    if((nums[pos] + opened) == (h - 1)){
        //fecha
        ans = (ans + solve(pos-1, opened+1)*(opened+1))%MOD;
        //unitario;
        ans = (ans + solve(pos-1, opened))%MOD;
        //fecha e abre
        ans = (ans + solve(pos-1, opened)*opened)%MOD;

    }
    return memo[pos][opened] = ans % MOD;

}

int main(){
    memset(memo, -1, sizeof memo);
    cin >> n >> h;
    for(int i=0;i<n;i++) cin >> nums[i];
    cout << solve(n-1, 0) << endl;

    return 0;
}