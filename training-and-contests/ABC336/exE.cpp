#include<bits/stdc++.h>
using namespace std;
//accepted
long long memo[15][127][127][2];
string s;
long long solve(int pos, int mod, int soma, bool tight, int k){

    if(pos >= (int)s.size()){
        return (mod == 0 && soma == k);
    }
    if(memo[pos][mod][soma][tight] != -1){
        return memo[pos][mod][soma][tight];
    }

    int limit = tight ? s[pos] - '0' : 9;
    long long ans = 0;
    for(int i=0;i<=limit;i++){
        bool newTight = tight && (i == limit);
        ans = ans + solve(pos+1, (mod*10 + i)%k, soma+i, newTight, k);
    }
    return memo[pos][mod][soma][tight] = ans;
}

int main(){

    
    cin >> s;
    long long result = 0;
    for(int i=1;i<=127;i++){

        memset(memo, -1, sizeof memo);
        result += solve(0, 0, 0, true, i);

    }
    cout << result << endl;

    return 0;
}