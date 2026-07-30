#include<bits/stdc++.h>
using namespace std;

const long long NMAX = 200005; // Margem de segurança um pouco maior
long long n;
vector<long long> cor;

// CORREÇÃO 1: Array estático de vectors (salva a compilação)
vector<pair<long long,long long>> adj[NMAX];

long long curr_ans = 0;
long long freq[NMAX];

long long ans[NMAX];
long long heavy[NMAX];
long long sz[NMAX];

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
    freq[c] += delta;
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
    // Otimização de I/O
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (!(cin >> n)) return 0;
    
    // CORREÇÃO 2: Compressão de Coordenadas
    map<long long, long long> comp;
    long long cor_id = 1;
    
    for(long long i = 0; i < n; i++){
        long long aux;
        cin >> aux;
        
        // Se a cor for inédita, damos um ID novo e seguro (<= NMAX) para ela
        if(comp.find(aux) == comp.end()){
            comp[aux] = cor_id++;
        }
        
        // Salvamos apenas o ID comprimido, que cabe no array 'freq'
        cor.push_back(comp[aux]);
    }

    memset(heavy, -1, sizeof heavy);

    for(long long i = 0; i < n - 1; i++){
        long long a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    dfssz(-1, 0);
    dfsDSU(0, -1, true);

    for(long long i = 0; i < n; i++){
        if(i) cout <<" ";
        cout << ans[i];
    }
    cout << "\n";

    return 0;
}