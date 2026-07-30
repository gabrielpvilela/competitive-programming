#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
const int NMAX =102, KMAX = 100001;
long long memo[NMAX][KMAX]; 
long long pref[NMAX][KMAX];
int N;

int main() {

	memset(memo, 0, sizeof memo);
	cin >> N;
	int k;
    cin >> k;
    vector<int> doces(N+1);
    for(int i=1;i<=N;i++)
        cin >> doces[i];
	
    memset(pref, 0, sizeof pref);

    memo[0][0] = 1;

    for(int i=1;i<=N;i++){
        
        vector<int> pre(k+1);
        pre[0] = memo[i-1][0];
        for(int j=1;j<=k;j++){
            pre[j] = (memo[i-1][j] + pre[j-1])%mod;
        }
        for(int j=0;j<=k;j++){
            long long soma = pre[j];
            if(j-doces[i] > 0)soma = (soma - pre[j-doces[i]-1] + mod)%mod;
            memo[i][j] = soma;
        }
    }
    cout << memo[N][k] << endl;
	return 0;

}