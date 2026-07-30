#include<bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b){
    return (a*b)/__gcd(a,b);
}

int main(){

    int t;
    cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;
        if(a == 1) cout << b*b << endl;
        else if(__){
            cout <<__gcd(a,b)*b << endl;
        }
    }

    return 0;
}