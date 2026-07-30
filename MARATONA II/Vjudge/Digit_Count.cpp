#include<bits/stdc++.h>
using namespace std;

long long memo[11][10][2];//bit, lastDigit, started
set<int> nums;


long long solve(int bit, int lastDigit, bool started){

    if(bit<0){
        return 1;
    }
    if(memo[bit][lastDigit][started] != -1){
        return memo[bit][lastDigit][started];
    }

    long long ans = 0;
    bool newStarted = true;
    for(int n : nums){
        if(started && abs(lastDigit - n) <= 2){
            ans += solve(bit-1, n, newStarted);
        }else if(!started){
            ans += solve(bit-1, n, newStarted);
        }
    }

    return memo[bit][lastDigit][started] = ans;
}

int main(){

    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        memset(memo, -1, sizeof(memo));
        nums.clear();
        int m, n;
        cin >> m >> n;
        for(int j=0;j<m;j++){
            int aux;
            cin >> aux;
            nums.insert(aux);
        }
        cout << "Case " << i << ": ";
        cout << solve(n-1, 0, false) << endl;
    }


    return 0;
}