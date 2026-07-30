#include<bits/stdc++.h>
using namespace std;

int moduloDeString(string s, int m){

    int ans = 0;
    for(int i=0;i<s.size();i++){
        ans= ans * 10 % m;
        ans = (ans + (s[i] -'0')) % m;
    }
    return ans;
}

int main(){

    string s;
    cin >> s;
    int n;
    cin >> n;

    int k = 4;
    int containt = 0;
    vector<int> pos;
    for(int i=0;i<s.size();i++) {
        if(s[i] == '?') {
            containt++;
            pos.push_back(i);
        }
    }

    sort(pos.rbegin(), pos.rend());


    bool temQfixarOPrim = false;

    k = min(k, containt);
    
    if(s[0] == '?') {
        k--;
        s[0] = '1';
        for(int i = 4; i < pos.size() - 1; i++) {
            s[pos[i]] = '0';
        }
    }
    else {
        for(int i = 4; i < pos.size(); i++) {
            s[pos[i]] = '0';
        }
    }
    //cout << pos[0] << endl;
    for(int i = 0; i<=9;i++){
        s[pos[0]] = (i + '0');
        //cout << s[pos[0]] << endl;
        if(k>1){
            for(int j=0;j<=9;j++){
                s[pos[1]] = (j + '0');
                if(k>2){
                    for(int p=0;p<=9;p++){
                        s[pos[2]] = (p + '0');
                        if(k>3){
                            for(int g=0;g<=9;g++){
                                s[pos[3]] = (g + '0');
                                if(moduloDeString(s, n) == 0) {
                                    cout << s << endl;
                                    return 0;
                                }
                            }
                        }
                        else {
                            if(moduloDeString(s, n) == 0) {
                                cout << s << endl;
                                return 0;
                            }
                        }
                    }
                }
                else {
                    if(moduloDeString(s, n) == 0) {
                        cout << s << endl;
                        return 0;
                    }
                }
            }
        }
        else {
            if(moduloDeString(s, n) == 0) {
                cout << s << endl;
                return 0;
            }
        }
    }

    cout << "*" << endl;

    return 0;
}