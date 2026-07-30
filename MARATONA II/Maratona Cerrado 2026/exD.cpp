#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i=0;i<q;i++){
        string r;
        cin >> r;
        int lcp = 0;
        int ans = 0;
        char prim = '0';
        for(int j=0;j<min(s.length(), r.length());j++){
            if(prim == '0') prim = s[j];
            if(s[j] == r[j] && s[j] == prim) lcp++;
            else break;
        }
        cout << r.size() + s.size() - lcp << endl;
    }


    return 0;
}