#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 67;

int sz[N];
int in[N], out[N];
int nxt[N];
int t = 0;
vector<vector<pair<int,int>>> g(N);
int vet[N], tree[8*N], lz[8*N];

void build(int node, int l, int r){
    if(l==r){
        tree[node] = vet[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*node + 1, l, mid);
    build(2*node + 2, mid + 1, r);
    tree[node] = tree[2*node + 1] + tree[2*node + 2];
}

void unlazy(int node, int tl, int tr){
    if(lz[node] == 0)
        return;
    tree[node] += (tr - tl + 1) * lz[node];
    if(tl!=tr){
        lz[2*node + 1] += lz[node];
        lz[2*node + 2] += lz[node];
    }
    lz[node] = 0;
}

void update(int node, int tl, int tr, int l, int r, int v){
    unlazy(node, tl, tr);
    if(tl > r || tr < l)
        return;
    if(tl >= l && tr <= r){
        lz[node] += v;
        unlazy(node, tl, tr);
        return;
    }
    int mid = (tl+tr)/2;
    update(2*node + 1, tl, mid, l, r, v);
    update(2*node + 2, mid+1, tr, l, r, v);
    tree[node] = tree[2*node + 1] + tree[2*node + 2];
}

int query(int node, int tl, int tr, int l, int r){

    unlazy(node, tl, tr);
    if(r < tl || l > tr)
        return 0;
    if(l <= tl && r >= tr)
        return tree[node];
    int mid = (tl+tr)/2;
    return query(2*node + 1, tl, mid, l, r) + query(2*node+2, mid+1, tr, l, r);

}

void dfs_sz(int v= 0, int pai = -1){
    sz[v] = 1;
    for(auto &u: g[v]){
        if(u.first == pai) continue;
        dfs_sz(u.first, v);
        sz[v]+=sz[u.first];
        if(sz[u.first] > sz[g[v][0].first]){
            swap(u, g[v][0]);
        }
    }
}

void dfs_hld(int v = 0, int pai = -1){
    in[v] = t++;
    for(auto [u,c]: g[v]){
        if(u == pai) continue;
        nxt[u] = (u == g[v][0].first ? nxt[v] : u);
        dfs_hld(u, v);
    }
    out[v] = t;
}


int main(){

    int n, q;
    cin >> n >> q;
    
    for(int i=0;i<n-1;i++){
        int x, y, c;
        cin >> x >> y >> c;
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }

    
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
    }


    return 0;
}