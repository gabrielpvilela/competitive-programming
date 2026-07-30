#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long int> p;
    vector<long long int> roots;
    string s;
    cin >> s;
    long long int sig = 1;
    if(s[0] == 'A') sig = -1;
    for(int i = 1; i < s.size(); i++){
        if(s[i] != s[i-1])
            roots.push_back(i*2+1);
    }

    if(roots.size() == 0){
        if(s[0] == 'A')
            cout << "0\n-1\n";
        else
            cout << "0\n1\n";
        return 0;
    }

    p.push_back(1);
    p.push_back(-roots[0]);

    for(int i = 1; i < roots.size(); i++){
        long long int r = roots[i];
        vector<long long int> ant = p;
        p.push_back(-p[p.size()-1]*r);
        for(int c = 1; c <= p.size()-2; c++){
            p[c] += -ant[c-1]*r;
        }
    }

    if(p.size()%2==0)
        sig*=-1;

    if(sig == -1){
        for(int c = 0; c <= p.size()-1; c++){
            p[c]*=-1LL;
        }
    }

    cout << p.size()-1 << endl;
    cout << p[0];
    for(int i =1; i < p.size(); i++){
        cout << ' ' << p[i];
    }
    cout << endl;
    return 0;
}