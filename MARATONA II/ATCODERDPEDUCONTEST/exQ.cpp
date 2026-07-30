#include<bits/stdc++.h>
using namespace std;

const long long NMAX = 200002;
long long BIT[NMAX];

void updateBit(long long tam, long long index, long long valor){
    index++;
    while(index<=tam){
        BIT[index] = max(valor, BIT[index]);
        index += index & (-index);
    }
}

void buildBit(){
    memset(BIT, 0, sizeof BIT);
}

long long queryBit(long long index){
    long long ans = 0;
    while(index > 0){
        ans = max(ans, BIT[index]);
        index -= index & (-index);
    }
    return ans;
}

int main(){

    long long dp[NMAX];
    memset(dp, 0, sizeof dp);
    buildBit();
    long long n;
    cin >> n;
    vector<long long> h(n), flor(n);
    for(long long i=0;i<n;i++){
        cin >> h[i];
    }
    for(long long i=0;i<n;i++){
        cin >> flor[i];
    }
    long long ans = 0;
    for(long long i=0;i<n;i++){
        dp[i] = max(dp[i], flor[i] + queryBit(h[i]));
        ans = max(dp[i], ans);
        updateBit(n, h[i], dp[i]);
    }
    
    cout << ans << endl;

    return 0;
}