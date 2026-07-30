#include<bits/stdc++.h>
using namespace std;

#define MAXN 19

string A, B;
long long memo[MAXN][10][2][2][2]; //bit, last digit, tightUp, tightLow, started;

long long solve(int bit, int lastDigit, bool tightUp, bool tightLow, bool started){

    if(bit >= B.length()){
        return 1;
    }
    if( memo[bit][lastDigit][tightUp][tightLow][started] != -1){
        return  memo[bit][lastDigit][tightUp][tightLow][started]; 
    }

    long long ans = 0;

    int limitUp = tightUp ? (B[bit] - '0') : 9;
    int limitDown = tightLow ? (A[bit] - '0') : 0;

    for(int i=limitDown; i<=limitUp; i++){
        bool newStarted = started ? true : (i ? true : false);
        bool newTightUp = tightUp ? ((i!=limitUp) ? false : true) : false;
        bool newTightLow = tightLow ? ((i!=limitDown) ? false : true) : false;
        if(!started){
            ans+=solve(bit+1, i, newTightUp, newTightLow, newStarted);
        }else if(i != lastDigit){
            ans+=solve(bit+1, i, newTightUp, newTightLow, newStarted);
        }
    }

    return memo[bit][lastDigit][tightUp][tightLow][started] = ans;
}

int main(){

    long long a, b;
    cin >> a >> b;
    string aux = to_string(a);
    B=to_string(b);
    for(int i =0;i<B.length()-aux.length();i++){
        A+='0';
    }
    A+=aux;
    memset(memo, -1, sizeof(memo));
    cout << solve(0, 0, true, true, false) << endl;


    return 0;
}