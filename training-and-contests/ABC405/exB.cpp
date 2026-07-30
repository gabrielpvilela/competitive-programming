#include<bits/stdc++.h>
using namespace std;
int main(){

    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    set<int> s;
    int pos;
    for(int i=0;i<n;i++){
        if(s.size() == m) break;
        pos = i;
        s.insert(nums[i]);
    }
    if(s.size() != m) cout << "0" << endl;
    else cout << n-pos << endl;

    return 0;
}