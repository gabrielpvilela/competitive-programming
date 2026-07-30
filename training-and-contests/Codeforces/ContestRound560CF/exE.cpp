#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    const int mod = 998244353;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    vector<long long> fator(n);
    vector<long long> mult(n);
    for(long long i=0;i<(n+1)/2;i++){
        fator[i] = (i+1)*(n-i);
        // cout << fator[i] << endl;
    }
    int aux = 1;
    for(int i=(n+1)/2;i<n;i++){
        fator[i] = fator[(n)/2 - aux];
        // cout << fator[i] << endl;
        aux++;
    }

    for(int i=0;i<n;i++){
        mult[i] = fator[i]*a[i];
    }

    sort(mult.begin(), mult.end());
    sort(b.rbegin(), b.rend());
    long long int ans = 0;
    for(int i=0;i<n;i++){
        ans = (ans + mult[i]%mod*b[i]%mod)%mod;
    }
    cout << ans << endl;

}