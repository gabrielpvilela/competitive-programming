#include<bits/stdc++.h>
using namespace std;

long long memo[20][20][2][2]; //pos, quant 0
int k = 3;
long long solve(int pos, int quantNzero, bool tightup, bool tightdown, string& n, string& r){

    if(pos >= n.size()){
        return quantNzero <= k;
    }
    if(memo[pos][quantNzero][tightup][tightdown] != -1) return memo[pos][quantNzero][tightup][tightdown];

    long long ans = 0;

    int limit = tightup ? r[pos] - '0' : 9;
    int limitD = tightdown ? n[pos] - '0' : 0;
    for(int i=limitD;i<=limit;i++){
        bool newTight = tightup && (i == (r[pos] - '0'));
        bool newTd = tightdown && (i== n[pos]-'0');
        int plus = i ? 1 : 0;
        ans = ans + solve(pos+1, quantNzero + plus, newTight, newTd,n, r); 
    }
    return memo[pos][quantNzero][tightup][tightdown] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        memset(memo, -1, sizeof memo);
        string l, r;
        cin >> l >> r;
        string aux;
        for(int i=l.size();i<r.size();i++) aux+="0";
        l = aux + l;
        long long ans = solve(0,0,true,true, l, r);
        //memset(memo, -1, sizeof memo);

        cout << ans << endl;
    }
    return 0;
}