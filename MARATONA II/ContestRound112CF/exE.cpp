#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin >> n;
    vector<int> a(1e6 + 1, 0);
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        a[aux]++;
    }
    int N = 20;
    vector<int> ans(n, -1);
    for(int i = 0; i<(1<<N); ++i)
	    F[i] = A[i];
    for(int i = 0;i < N; ++i) 
        for(int mask = 0; mask < (1<<N); ++mask){
	    if(mask & (1<<i))
		    if(ans[])F[mask] += F[mask^(1<<i)];
        }

    return 0;
}