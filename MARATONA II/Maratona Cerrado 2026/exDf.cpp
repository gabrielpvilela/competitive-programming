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
        int ans = 0;
        for(int i1 = 0; i1 < s.size(); i1++){
            for(int j1 = 0; j1+i1 <= s.size(); j1++){
                string s1 = s.substr(i1, j1);
                for(int i2 = 0; i2 < r.size(); i2++){
                    for(int j2 = 0; j2+i2 <= r.size(); j2++){
                        string r1 = r.substr(i2, j2);

                        int lcp;
                        for(lcp = 0; lcp < min(r1.size(), s1.size()); lcp++)
                            if(s1[lcp] != r1[lcp]) break;
                        //cout << s1 << ' ' << r1 << ": " << (int)s1.size()+(int)r1.size() - 2*lcp << endl;
                        ans = max(ans, (int)s1.size()+(int)r1.size() - 2*lcp);
                    }
                }
            }
        }
        cout << ans << endl;
    }


    return 0;
}