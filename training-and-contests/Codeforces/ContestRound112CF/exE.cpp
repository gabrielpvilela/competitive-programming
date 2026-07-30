#include<bits/stdc++.h>
using namespace std;
const int BMAX = 22;
int main(){

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];

    vector<int> A((1<<BMAX), -1);

    for(int i=0;i<n;i++) A[nums[i]] = nums[i];
    vector<int> F((1<<BMAX));
    for(int i = 0; i<(1<<BMAX); ++i)
	    F[i] = A[i];
    for(int i = 0;i < BMAX; ++i) for(int mask = 0; mask < (1<<BMAX); ++mask){
	    if(mask & (1<<i))
    		F[mask] = max(F[mask], F[mask^(1<<i)]);
    }

    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int num = nums[i];
        for(int j=0;j<BMAX;j++) num = (num ^ (1 << j));
        ans[i] = F[num];
    }
    for(int i=0;i<n;i++){
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}