#include<bits/stdc++.h>
using namespace std;

long long memo[19][2][2][2]; //pos, firstDigit,  
string l, r;
long long solve(int pos, bool tightLow, bool tightHigh, int k, bool comecou){
    if(memo[pos][tightLow][tightHigh][comecou] != -1){
        return memo[pos][tightLow][tightHigh][comecou];
    }

    long long ans = 0;
    int low = tightLow ? l[pos] - '0' : 0;
    int high = tightHigh ? r[pos] - '0' : 9;
    // if(!comecou){
    //     low = k;
    //     high = k;
    // }
    for(int i=low;i<=high;i++){
        if(pos == r.size() - 1){
            ans += (i == k) ? 1 : 0;
        }else{

            bool newUp = tightHigh && (i==r[pos] - '0');
            bool newLow = tightLow && (i==l[pos] - '0');
            bool newCom = comecou || i != 0;
            if(!comecou && (i == 0 || i == k))
                ans += solve(pos + 1, newLow, newUp, k, newCom);
            else if(comecou)
                ans += solve(pos + 1, newLow, newUp, k, newCom);

        }
    }
    return memo[pos][tightLow][tightHigh][comecou] = ans;
}

int main(){

    cin >> l >> r;
    string aux;
    for(int i=l.size();i<r.size();i++) aux+="0";
    l = aux + l;
    long long ans = 0;
    for(int i=1;i<=9;i++){
        memset(memo, -1, sizeof memo);
         
        ans += solve(0, true, true, i, false);
        // cout << ans << endl;
    }
    // cout << l << " " << r << endl; 
    cout << ans << endl;

    return 0;
}