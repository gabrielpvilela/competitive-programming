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
    ordered_set s;
    while(t--){
        char op;
        long long n;
        cin >> op >> n;
        if(op == 'I'){
            s.insert(n);
        }else if(op == 'D'){
            s.erase(n);
        }else if(op == 'C'){
            cout << s.order_of_key(n) << endl;
        }else{
            n--;
            if(n >= s.size()) cout << "invalid" << endl;
            else cout << *s.find_by_order(n) << endl;
        }
    }

    return 0;
}