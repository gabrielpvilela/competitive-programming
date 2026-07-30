#include<bits/stdc++.h>
using namespace std;

int main(){

    long long t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> nums(2001, vector<int>(15, 0));
        
        for(int i=1;i<=2000;i++){
            for(int j=0;j<15;j++){
                nums[i][j] += nums[i-1][j];
                nums[i][j] += ((i >> j) & 1);    
            }
        }
        int lg = 31 - __builtin_clz(n);;
        vector<string> s(lg+1);
        map<int,int> c;
        bool deuRuim = false;
        for(int i=0;i<=lg;i++){
            cin >> s[i];
            int conta = 0;
            for(int j=0;j<n;j++){
                if(s[i][j] == '1') conta++;
            }
            c[conta]++;
        }

        long long ans = 1;
        vector<long long> mult(2000, 1);
        for(long long i=1;i<2000;i++){
            mult[i] = mult[i-1] * i;
        }

        map<int,int> m2;
        for(int i=0;i<15;i++){
            m2[nums[n][i]]++;
        }
        
        for(auto m : c){    
            ans *= mult[m.second];
            if(m.second != m2[m.first]) deuRuim = true;
        }
        if(deuRuim){
            cout << "0" << endl;
            continue;
        }
        cout << ans << endl;
    }

    return 0;
}