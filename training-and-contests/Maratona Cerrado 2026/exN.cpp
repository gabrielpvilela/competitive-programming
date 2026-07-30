#include <bits/stdc++.h>
using namespace std;

int main(){
    string h1, h2;
    cin >> h2 >> h1;
    int h = 10*(h2[0]-'0') + h2[1]-'0';
    int m = 10*(h2[3]-'0') + h2[4]-'0';
    int hh = 10*(h1[0]-'0') + h1[1]-'0';
    int mm = 10*(h1[3]-'0') + h1[4]-'0';

    int mi = m-mm;
    int hi = h-hh;
    if(mi < 0){
        hi--;
        mi+=60;
    }
    if(mi >= 60){
        mi -= 60;
        hi++;
    }
    if(hi < 0)
        hi+=24;
    string res;
    res.push_back(hi/10+'0');
    res.push_back(hi%10+'0');
    res.push_back(':');
    res.push_back(mi/10+'0');
    res.push_back(mi%10+'0');
    cout << res << endl;
    return 0;
}