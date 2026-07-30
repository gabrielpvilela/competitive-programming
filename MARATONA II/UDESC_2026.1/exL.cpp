#include<bits/stdc++.h>
using namespace std;


int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    long long n;
    cin >> n;
    if(n == 2) cout << "0" << endl;
    else cout << 63 - __builtin_clzll(n-1) << endl;

    return 0;
}