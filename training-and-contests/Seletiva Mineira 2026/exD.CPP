#include <bits/stdc++.h>
using namespace std;

long long fat[2000001];
long long invfat[2000001];
#define mod 1000000007

long long mod_inv(long long a, int m){
	if(a<=1) return a;
	return m - (long long)(m/a) * mod_inv(m%a, m)%m;
}

void precomputar() {
    int N = 2000000;
    fat[0] = 1;
    for(int i = 1; i <= N; i++) {
        fat[i] = (1LL * fat[i-1] * i) % mod;
    }
    invfat[N] = mod_inv(fat[N], mod);
    for(int i = N - 1; i >= 0; i--) {
        invfat[i] = (1LL * invfat[i+1] * (i + 1)) % mod;
    }
}

long long choose(int m, int n){
	if(n <= 0 || m <= 0) return 0;
	if(n==1 || m==1) return 1;
	return (((fat[m+n-2] * invfat[m-1])%mod) * invfat[n-1])%mod;
}

int main() {
	
	int n,m,k;
	cin >> n >> m >> k;
	
	precomputar();
	vector<pair<int,int>> pares;
	for(int i=0;i<k;i++){
		int x, y;
		cin >> x >> y;
		pares.push_back({x,y});
	}
	
	sort(pares.begin(), pares.end());
	
	long long total = choose(m, n);
	
	
	vector<long long> subindo(k, -1);
	
	for(int i=0;i<k;i++){
		long long subir = choose(pares[i].first, pares[i].second);
		
		for(int j=0;j<i;j++){
			subir =  (subir - ((subindo[j] * choose(pares[i].first - pares[j].first + 1, pares[i].second - pares[j].second + 1))%mod) + mod) % mod;
		}
		subindo[i] = subir;
	}
	
	for(int i=0;i<k;i++){
		total = (total - ((subindo[i] * choose(n - pares[i].first + 1, m - pares[i].second + 1))%mod) + mod)%mod;
	}
	
	cout << total << endl;
	return 0;

}