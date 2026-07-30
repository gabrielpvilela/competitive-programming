#include<bits/stdc++.h>
using namespace std;

int main(){
    srand(time(NULL));
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    while(true){
        string r;
        for(int j = 0; j < s.size(); j++){
            r.push_back('a'+(rand()%26));
        }
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
        int lcp = 0;
        for(int j=0;j<min(s.length(), r.length());j++){
            if(s[j] == r[j]) lcp++;
            else break;
        }
        //cout << r.size() + s.size() - lcp << endl;
        if(ans != r.size() + s.size() - lcp){
            cout << s << ' ' << r << endl;
            cout << ans << ' ' << r.size()+s.size()-lcp << endl;
            break;
        }
    }


    return 0;
}