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
        int n;
        cin >> n;
        vector<int> nums(4*n, -1);
        for(int i=1;i<=n;i++){
            if(i > n/2) break;
            for(int j=0;j<4*n;j++){
                if(nums[j] == -1){
                    nums[j] = i;
                    nums[j+3] = i;
                    nums[j+2] = i;
                    nums[j+6] = i;
                    nums[4*n-j-7] = nums[4*n-j-3] = nums[4*n-j-4] = nums[4*n-j-1] = n-i+1;
                    break;
                }
            }
        }
            // for(int i=0;i<4*n;i++){
            //     //if(nums[i] == -1) nums[i] = n/2 + 1;
            //     if(i) cout << " ";
            //     cout << nums[i];
            // }
            for(int i=0;i<4*n;i++){
                if(nums[i] == -1) nums[i] = n/2 + 1;
                if(i) cout << " ";
                cout << nums[i];
            }
            cout << endl;
        
        
    }

    return 0;
}