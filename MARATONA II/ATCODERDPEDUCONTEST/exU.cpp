#include<bits/stdc++.h>
using namespace std;

const int NMAX = 16;

int n;
int mat[NMAX][NMAX];

int main(){

    long long C[1 << NMAX];
    memset(C, 0, sizeof C);
    C[0] = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }
    for(int i=1;i<(1<<n);i++){
        long long custo = 0;
        for(int j=0;j<n;j++){
            for(int k=j;k<n;k++){
                if(((i>>k) & 1) && ((i>>j) & 1)){
                    custo += mat[j][k];
                }
            }
        }
        C[i] = custo;
        // cout << C[i] << " ";
    }
    // cout << endl;

    //101;

    vector<long long> sos(1 << n);

    for (int x = 0; x < (1 << n); x++) {
	    sos[x] = 0;
	    // iterate over all subsets of x directly
	    for (int i = x; i >= 0; i = (i - 1) & x) { sos[x] = max(sos[x], sos[i] + C[x-i]); if(!i) break;}
    }
    //1111
    //1100 
    // cout << sos[0] << endl;
    cout << sos[(1<<n) - 1] << endl;
    // for(int i=0;i<(1<<n);i++) cout << sos[i] << " ";
    // cout << endl;
    return 0;
}