#include<bits/stdc++.h>
using namespace std;

long long memo[102][102][2]; //pos, quant 0
string n;
int k;
long long solve(int pos, int quantzero, bool tight){

    if(pos >= n.size()){
        return quantzero == n.size() - k;
    }
    if(memo[pos][quantzero][tight] != -1) return memo[pos][quantzero][tight];

    long long ans = 0;

    int limit = tight ? n[pos] - '0' : 9;
    for(int i=0;i<=limit;i++){
        bool newTight = tight && (i == (n[pos] - '0'));
        int plus = i ? 0 : 1;
        ans = ans + solve(pos+1, quantzero + plus, newTight); 
    }
    return memo[pos][quantzero][tight] = ans;
}

int main(){

    memset(memo, -1, sizeof memo);
    cin >> n >> k;

    cout << solve(0,0,true) << endl;

    return 0;
}