#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    bool deuRuim = false;
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        aux--;
        if(nums[aux] != i) deuRuim = true;
    }
    cout << (deuRuim ? "No" : "Yes") << endl;
    return 0;
}