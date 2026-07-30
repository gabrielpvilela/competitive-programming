#include<bits/stdc++.h>
using namespace std;

int main(){

    long long t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        if(n == 2){
            cout << "1 2 1 2 2 1 1 2\n";
            continue;
        }
        
        vector<int> nums(4 * n);
        
        for(int i = 0; i < n; i++){
            nums[i] = i + 1;
            nums[i + n] = i + 1;
            nums[2 * n + (i + 1) % n] = i + 1;
            nums[3 * n + (i + 3) % n] = i + 1;
        }
        
        for(int i = 0; i < 4 * n; i++){
            if(i) cout << " ";
            cout << nums[i];
        }
        cout << "\n";
    }

    return 0;
}