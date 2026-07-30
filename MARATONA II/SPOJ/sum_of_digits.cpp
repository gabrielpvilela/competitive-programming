#include<bits/stdc++.h>
using namespace std;

long long memo[10][92][2][2]; //pos, Soma digitos, baixo, alto
string a, b;
long long solve(int pos, int soma, bool tightLow, bool tightHigh){

    if(pos >= a.size()){
        return soma;
    }
    if(memo[pos][soma][tightLow][tightHigh] != -1){
        return memo[pos][soma][tightLow][tightHigh];
    }

    int limitLow = tightLow ? a[pos] - '0' : 0;
    int limitHigh = tightHigh ? b[pos] - '0' : 9;
    long long ans = 0;
    for(int i=limitLow;i<=limitHigh;i++){
        bool newTightLow = tightLow && (i == limitLow);
        bool newTightHigh = tightHigh && (i == limitHigh);
        ans += solve(pos+1, soma+i, newTightLow, newTightHigh);
    }
    return memo[pos][soma][tightLow][tightHigh] = ans;
}

int main(){

    cin >> a >> b;
    while(a!="-1" && b!="-1"){
        memset(memo, -1, sizeof memo);
        string espacos;
        int aux = b.size() - a.size();
        while(aux--) espacos += "0";
        a = espacos + a;

        cout << solve(0,0,true, true) << endl;
        cin >> a >> b;
    }
    
    return 0;
}