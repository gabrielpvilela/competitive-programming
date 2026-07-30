#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;
        vector<int> num = {2, 3, 5, 7};
        int bit = 1;
        long long ans = b;
        a--;
        while(bit < (1 << 4)){
            int mult = 1;
            for(int i=0;i<4;i++){
                if((bit >> i) & 1) mult *= num[i];
            }
            if(__builtin_popcount(bit)%2){
                ans -= b/mult;
            }else{
                ans += b/mult;
            }

            bit++;
        }
        long long ansA = a;
        bit = 1;
        while(bit < (1 << 4)){
            int mult = 1;
            for(int i=0;i<4;i++){
                if((bit >> i) & 1) mult *= num[i];
            }
            if(__builtin_popcount(bit)%2){
                ansA -= a/mult;
            }else{
                ansA += a/mult;
            }

            bit++;
        }
        cout << ans - ansA << endl;
    }

    return 0;
}