#include<bits/stdc++.h>
using namespace std;

long long const mod = 1e9 + 7;
long long fat[1001];
long long invfat[1001];

long long mod_inv(long long a){
	if(a<=1) return a;
	return mod - (long long)(mod/a) * mod_inv(mod%a)%mod;
}

void precompute(){
    fat[0] = 1;
    for(long long i=1;i<1001;i++)
        fat[i] = i * fat[i-1] % mod;

    invfat[1000] = mod_inv(fat[1000]);

    for(long long i = 999; i>=0;i--)
        invfat[i] = invfat[i+1] * (i+1) % mod;  

}

long long choose(int big, int smal){
    if(big < smal || smal < 0) return 0;


    return (((fat[big] * invfat[big - smal])%mod) * invfat[smal])%mod;
}




int main(){

    string s;
    cin >> s;
    precompute();
    int contaA = 0, contaV = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'A') contaA++;
        else contaV++;
    }
    int n, m;
    cin >> n >> m;
    long long num = choose(n+m, s.size()) * choose(n+m-s.size(), n - contaA) % mod;
    long long den = choose(n+m, n);

    long long ans = num * mod_inv(den) % mod;

    cout << ans << endl;

    return 0;
}