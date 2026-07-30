#include <bits/stdc++.h>
using namespace std;

struct aresta{
    int u, v, peso;
    bool operator<(const aresta &other) const{
        return peso < other.peso;
    }
};

vector<int> pai;
vector<int> tamanho;

int find(int i){
    if(pai[i] == i)
        return i;
        return pai[i] = find(pai[i]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(tamanho[a] < tamanho[b])
            swap(a,b);
        pai[b] = a;
        tamanho[a] += tamanho[b];
    }
}

const int N = 112345;
const int LN = 20;
int depth[N], memo[LN][N], maxmemo[LN][N];
vector<pair<int, int>> filhos[N];

void dfs(int s){
    for(int i = 0; i < filhos[s].size(); i++){
        int f = filhos[s][i].first;
        int w = filhos[s][i].second;
        if(memo[0][s] == f)continue;
        depth[f] = depth[s]+1;
        memo[0][f] = s;
        maxmemo[0][f] = w;
        dfs(f);
    }
}

void compute(int n){
    for(int p = 1; p < LN; p++){
        for(int i = 0; i < n; i++){
            memo[p][i] = memo[p-1][memo[p-1][i]];
            maxmemo[p][i] = max(maxmemo[p-1][i], maxmemo[p-1][memo[p-1][i]]);
        }
    }
}

pair<int,int> walk(int s, int dis){
    int j = 0;
    int res = 0;
    while(dis){
        if(dis&1){
            res = max(res, maxmemo[j][s]);
            s = memo[j][s];
        }
        j++;
        dis>>=1;
    }

    return {s, res};
}

int lca(int x, int y){
    if(depth[x] < depth[y]) swap(x,y);
    int res = 0;
    auto wa = walk(x, depth[x]-depth[y]);
    x = wa.first;
    res = max(res, wa.second);

    if(x == y) return res;
    for(int k = LN-1; k>= 0; k--){
        if(memo[k][x] != memo[k][y]){
            res = max(res, maxmemo[k][x]);
            res = max(res, maxmemo[k][y]);
            x = memo[k][x];
            y = memo[k][y];
        }
    }
    return max({res, maxmemo[0][x], maxmemo[0][y]});
}

long long kruskal(int n, vector<aresta> &arestas){
    pai.resize(n);
    iota(pai.begin(), pai.end(), 0);
    tamanho.assign(n, 1);

    sort(arestas.begin(), arestas.end());
    long long ans = 0;
    vector<aresta> mst;

    for(const auto& ar : arestas){
        if(find(ar.u) != find(ar.v)){
            ans += 1ll*ar.peso;
            mst.push_back(ar);
            filhos[ar.u].push_back({ar.v, ar.peso});
            filhos[ar.v].push_back({ar.u, ar.peso});
            unite(ar.u, ar.v);
        }
    }


    return ans;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(0);
    int n, r;
    cin >> n >> r;

    vector<aresta> ar;
    map<pair<int,int>,int> car;
    for(int i = 0; i < r; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a > b)
            swap(a,b);
        ar.push_back({a-1,b-1,c});
        car[{a-1, b-1}] = c;
    }

    long long ms=kruskal(n, ar);
    dfs(0);
    compute(n);


    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(a>b)
            swap(a,b);
        //cout << ms << ' ' << car[{a-1, b-1}] << ' ' << lca(a-1, b-1) << endl;
        cout << ms+1ll*car[{a-1, b-1}] -1ll*lca(a-1, b-1) << endl;
    }
    return 0;
}