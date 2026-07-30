#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
long long,
null_type,
less<long long>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ordered_set s;
        vector<long long> nums(n);
        for(int i=0;i<n;i++) {
            cin >> nums[i];
        }
        long long ans = 0;
        for(int i=n-1;i>=0;i--){
            
            ans += s.order_of_key(nums[i]);
            s.insert(nums[i]);
        }
        cout << ans << endl;
    }

    return 0;
}