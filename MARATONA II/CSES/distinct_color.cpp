#include<bits/stdc++.h>
using namespace std;

const long long NMAX = 200001;
long long n;
vector<long long> cor;
vector<vector<pair<long long,long long>>> adj(NMAX);

long long curr_ans = 0;
long long freq[NMAX];

long long ans[NMAX];
long long heavy[NMAX];
long long sz[NMAX];
long long tot[NMAX];

long long dfssz(long long p, long long v){
    long long curHeavy = 0;
    sz[v] = 1;
    for(auto u : adj[v]){
        if(u.first == p) continue;
        long long peso = dfssz(v, u.first);
        if(peso > curHeavy){
            curHeavy = peso;
            heavy[v] = u.first;
        }
        sz[v] += peso;
    }
    return sz[v];
}

void update(long long c, long long delta){
    if(!freq[c] && delta > 0) curr_ans++;
    //curr_ans -= freq[c] * (tot[c]-freq[c]);
    freq[c] += delta;
    //curr_ans += freq[c] * (tot[c]-freq[c]);
    if(!freq[c]) curr_ans--;
}

void addSub(long long v, long long delta, long long p = -1){
    update(cor[v], delta);
    for(auto u : adj[v]){
        if(u.second == p) continue;
        addSub(u.first, delta, u.second);
    }
}

void dfsDSU(long long v, long long aresta_p, bool keep){

    for(auto u : adj[v]){
        if(u.second == aresta_p || u.first == heavy[v]) continue;
        dfsDSU(u.first, u.second, false);
    }

    if(heavy[v] != -1){
        for(auto u : adj[v]){
            if(u.second == aresta_p || u.first != heavy[v]) continue;
            dfsDSU(u.first, u.second, true);
        }
    }

    for(auto u :adj[v]){
        if(u.second == aresta_p || u.first == heavy[v]) continue;
        addSub(u.first, 1, u.second);
    }

    update(cor[v], 1);

    ans[v] = curr_ans;

    if(!keep){
        addSub(v, -1, aresta_p);
    }

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    for(long long i=0;i<n;i++){
        long long aux;
        cin >> aux;
        cor.push_back(aux);
        tot[aux]++;
    }

    memset(heavy, -1, sizeof heavy);

    for(long long i=0;i<n-1;i++){
        long long a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    dfssz(-1, 0);
    dfsDSU(0, -1, true);

    for(long long i=0;i<n;i++){
        if(i) cout <<" ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}