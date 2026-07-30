#include<bits/stdc++.h>
using namespace std;

#define MAXN 10001
long long int MOD = 1000000007;
long long memo[MAXN][2][101][2]; //bits, isTight, mod;
int D;
string K;
long long solve(int bit, bool isTight, int m, int hasStarted){

    if(bit < 0){
        return !hasStarted ? 0 : (m ? 0 : 1);
    }
    if(memo[bit][isTight][m][hasStarted] != -1){
        return memo[bit][isTight][m][hasStarted];
    }
    long long ans = 0;

    int limit = isTight ? (K[K.length() - 1 - bit] - '0') : 9;
    for(int i=0;i<=limit;i++){
        bool newIsTight = !isTight ? false : (i==limit ? true : false);
        bool newStarted = hasStarted ? true : (i ? true : false); 
        int newM = (m + i) % D; 
        ans += solve(bit-1, newIsTight, newM, newStarted) % MOD;
    }

    return memo[bit][isTight][m][hasStarted] = ans % MOD;
}

int main(){
    
    memset(memo, -1, sizeof(memo));
    string k;
    cin >> k;
    int d;
    cin >> d;
    K=k;
    D=d;

    cout << solve(K.length()-1, true, 0, false) << endl;

    return 0;
}