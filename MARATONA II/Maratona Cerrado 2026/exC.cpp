#include <bits/stdc++.h>
using namespace std;

vector<long long> prefix_function(const string& s) {
    long long n = s.length();
    vector<long long> pi(n);

    for(long long i = 1; i < n; i++) {
        long long j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vector<long long> kmp(const string& t, const string& s) {
    vector<long long> pi = prefix_function(s);
    vector<long long> match;
    for(long long i = 0, j = 0; i < t.length(); i++) {
        while(j > 0 && t[i] != s[j]) j = pi[j - 1];
        if(t[i] == s[j]) j++;
        if(j == s.length()) {
            match.push_back(i - j + 1);
            j = pi[j - 1];
        }
    }
    return match;
}

int main() {
    long long n;
    string S1, T;
    string S;
    cin >> S1;
    n = S1.size();

    while(S.size() < 5e6) S += S1;

    cin >> T;
    //cout << S << " " << T << endl;

    vector<long long> occ = kmp(S, T);

    //for(long long i = 0; i < occ.size(); i++) cout << occ[i] << " ";
    //cout << endl;

    vector<long long> somas(n);
    for(long long i = 0; i < n; i++) {
        cin >> somas[i];
    }

    vector<long long> sum;
    long long cur = 0;
    long long maxs = 0;
    bool aoba = false;
    for(long long i = 0; i < occ.size(); i++){
        long long v = somas[occ[i]%n];
        long long tam = 1;
        sum.push_back(v);
        while(i+1 < occ.size() && occ[i+1]-occ[i] == T.size()){
            sum[cur] += somas[occ[i+1]%n];
            i++;
            tam++;
        }
        if(tam*T.size() > n)
            aoba = true;
        maxs = max(maxs, sum[cur]);
        cur++;
    }
    if(aoba)
        cout << -1 << endl;
    else cout << maxs << endl;

    
    return 0;
}