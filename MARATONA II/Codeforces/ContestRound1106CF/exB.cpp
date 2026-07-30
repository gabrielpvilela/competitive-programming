#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long total = 0;
        for(long long i=1;i<=n;i++){
            total += (n/i) * (n/i);
        }
        cout << total <<endl;
    }
    return 0;
}