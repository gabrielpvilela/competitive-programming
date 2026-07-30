#include<bits/stdc++.h>
using namespace std;

bool solve(long long mid, long long n, long long x, long long y, long long z){

    long long tempo1 = mid*x;
    long long tempo2 = max((mid-z) * y*10, mid*y);
    if(tempo1+tempo2 >= n) return true;
    else return false;

}
 
int main(){

    long long t;
    cin >> t;
    while(t--){
        long long n, x, y, z;
        cin >> n >> x >> y >>z;
        
        long long l = 1, r = 10001, ans = -1;
        while(l<=r){
            long long mid = (l+r)/2;
            if(solve(mid, n, x, y, z)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}