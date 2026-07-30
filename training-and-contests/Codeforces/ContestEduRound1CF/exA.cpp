#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        long long ans;
        long long n;
        cin >> n;
        ans = ((n+1)*n)/2;
        long long p = 1;
        while(p <= n){
            ans-=2ll*p;
            p*=2ll;
        }
        cout << ans << endl;
    }

    return 0;
}