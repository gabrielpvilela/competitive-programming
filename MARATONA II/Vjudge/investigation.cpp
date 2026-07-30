#include<bits/stdc++.h>
using namespace std;

#define MAXN 10
string A, B;
int K;

long long memo[MAXN][2][2][91][91];//bit, tightUp, tightDown, m  
//se k maior q 90 nem funfa
long long solve(int bit, bool tightUp, bool tightDown, int mTot, int mDigits){

    if(bit<0){
        return (!mTot && !mDigits) ? 1 : 0;
    }
    if(memo[bit][tightUp][tightUp][mTot][mDigits] != -1){
        return memo[bit][tightUp][tightUp][mTot][mDigits];
    }

    int limitUp = tightUp ? (B[B.length() - 1 - bit] - '0') : 9;
    int limitDown = tightDown ? (A[A.length() - 1 - bit] - '0') : 0;
    long long ans = 0;

    for(int i = limitDown; i<= limitUp;i++){
        bool newTightUp = tightUp && (i == limitUp);
        bool newTightDown = tightDown && (i==limitDown);
        int newMTot = ((mTot*10) + i) % K;
        int newMDigits = (mDigits + i) % K;
        
        ans += solve(bit-1, newTightUp, newTightDown, newMTot, newMDigits);

    }


    return memo[bit][tightUp][tightDown][mTot][mDigits] = ans;
}

int main(){

    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        memset(memo, -1, sizeof(memo));
        string a, b;
        cin >> a >> b;
        int k;
        cin >> k;
        K=k;
        string zeros = "";
        for(int j=0;j<b.length()-a.length();j++){
            zeros+='0';
        }
        B = b;
        A = zeros + a;

        cout << "Case " << i << ": ";
        if(k>90){
            cout << "0" << endl;
        }
        else {
            cout << solve(B.length()-1, true, true, 0, 0) << endl;
        }
    }

    return 0;
}