#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<long long> res(41);
    res[0] = 1LL;
    res[1] = 1LL;
    res[2] = 2LL;
    for(int i=3;i<41;i++){
        res[i] = res[i-3] + 2LL*res[i-1];
    }
    int n;
    cin >> n;
    cout << res[n] << endl;

    return 0;
}