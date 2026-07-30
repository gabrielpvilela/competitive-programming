#include<bits/stdc++.h>
using namespace std;



int main(){

    int n;
    cin >> n;
    vector<int> m(n+1, 0);

    for(int i=1;i<=n;i++){
        cin >> m[i];
    }
    sort(m.begin(), m.end());
    int nmax = 100001;
    pair<int,int> dp[100001];
    memset(dp, 0, sizeof dp);
    dp[0].first = 1;
    for(int j=1;j<=n;j++){    
        for(int i=1;i<100001;i++){
            if(i>=m[j] && dp[i-m[j]].second != j && !dp[i].first) {dp[i].first |= dp[i-m[j]].first; dp[i].second = j;}
        }
    }
    int conta = 0;
    bool primeiro = true;
    for(int i=1;i<nmax;i++){
        if(dp[i].first) conta++;
    }
    cout << conta << endl;
    for(int i=1;i<nmax;i++){
        if(dp[i].first){
            if(primeiro){
                primeiro = false;
                cout << i;
            }else{
                cout << " " << i;
            }
        }
    }
    cout << endl;


    return 0;
}