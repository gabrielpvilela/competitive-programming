#include <bits/stdc++.h>
using namespace std;

const long long maxn = 10000001;
vector<bool> is_prime(maxn, true);
vector<int> divs(maxn, 1);
vector<long long int> pricount(maxn, 0);

void sieve(){
    is_prime[0] = is_prime[1] = false;
    for(long long p = 2; p*p < maxn; p++){
        if(is_prime[p]){
            divs[p] = p;
            for(long long i = p*p; i < maxn; i+=p){
                is_prime[i] = false;
                divs[i] = p;
            }
        }
    }
    for(int i = 3; i < maxn; i+=2)
        if(is_prime[i])
            divs[i] = i;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    sieve();
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

   /* map<int,int> pricount;
    for(int i = 2; i < maxn; i++)
        if(is_prime[i])
            pricount.insert({i, 0});*/
    
    for(auto e : a){
        while(e > 1){
            pricount[divs[e]]+=1ll*divs[e];
            e /= divs[e];
            if(divs[e] == 1) break;
        }
    }

    vector<long long> c;
    for(auto pc: pricount)
        if(pc)
            c.push_back(pc);
    sort(c.rbegin(), c.rend());
    long long res = 0;
    for(int i = 0; i < c.size(); i+=2)
        res += c[i];
    cout << res << endl;

    return 0;
}