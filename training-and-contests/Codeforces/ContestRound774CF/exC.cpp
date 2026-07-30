#include<bits/stdc++.h>
using namespace std;

int main(){

        int t;
        cin >> t;
        long long fat[16];
        fat[0] = 1;
        for(long long i=1;i<16;i++){
            fat[i] = fat[i-1]*i;
        }
        for(int i=0;i<16;i++) if(__builtin_popcountll(fat[i]) == 1) fat[i] = 0;
        while(t--){
            long long n;
            cin >> n;
            int bestAns = 1000;
            for(int i=0;i<(1<<16);i++){
                long long aux = n;
                int conta = 0;
                for(int j=0;j<16;j++){
                    if((i >> j) & 1) {
                        aux -= fat[j];
                        conta++;
                    }
                }
                if(aux >= 0) bestAns = min(bestAns, conta + __builtin_popcountll(aux));
            }
            cout << bestAns << endl;
        }
    

    return 0;
}