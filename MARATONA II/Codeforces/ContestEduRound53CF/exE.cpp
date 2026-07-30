#include<bits/stdc++.h>
using namespace std;

const int tambitmask = 1 << 10;
const int mod = 998244353;
int k;
pair<long long, long long> memo[19][tambitmask][2][2][2];//pos, mask, tightlow, tighthigh, comecou
string l, r;
long long pot10[20];
pair<long long, long long> solve(int pos, int mask, bool tightLow, bool tightHigh, bool comecou){

    if(pos >= r.size()){
        return {__builtin_popcount(mask) <= k, 0};
    }
    if(memo[pos][mask][tightLow][tightHigh][comecou].first != -1){
        return memo[pos][mask][tightLow][tightHigh][comecou];
    }

    long long ans = 0, somaAcum = 0;
    int low = tightLow ? l[pos] - '0' : 0;
    int high = tightHigh ? r[pos] - '0' : 9;

    for(int i=low;i<=high;i++){
        bool newHigh = tightHigh && (i == high);
        bool newLow = tightLow && (i == low);
        bool newCom = comecou || i;
        if(!newCom){
            pair<long long, long long> ret = solve(pos+1, mask,  newLow, newHigh, newCom);
            ans = (ans + ret.first) % mod;
            somaAcum = (somaAcum + (i * pot10[r.size() -pos] %mod * ret.first%mod) + ret.second)%mod; 
        }else{
            int newmask = mask | (1 << i);
            pair<long long, long long> ret = solve(pos+1, newmask, newLow, newHigh, newCom);
            ans = (ans + ret.first) % mod;
            somaAcum = (somaAcum + (i * pot10[r.size() -pos -1]%mod * ret.first%mod) + ret.second)%mod;
        } 
    }
    return memo[pos][mask][tightLow][tightHigh][comecou] = {ans, somaAcum};

}

int main(){

    cin >> l >> r >> k;
    memset(memo, -1, sizeof memo);
    pot10[0] = 1;
    for(int i=1;i<20;i++){
        pot10[i] = pot10[i-1] * 10 % mod;
    }
    // cout << tambitmask << endl;
    string aux;
    for(int i = l.size(); i < r.size();i++) aux+="0";
    l = aux + l;

    cout << solve(0, 0, true, true, false).second << endl;

    return 0;
}