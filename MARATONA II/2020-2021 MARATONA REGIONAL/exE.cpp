#include<bits/stdc++.h>
using namespace std;

const int N = 212345;
const int LN = 20;


int depth[N], memo[LN][N];
vector<int> filhos[N];

int bit[N];

void updateBIT(int index, int valor){
    index++;
    while(index<=N){
        bit[index] += valor;
        index += index & (-index);
    }
}

void buildBIT(){
    memset(bit, 0, sizeof(bit));
}

int queryBIT(int idx){
    int soma = 0;
    while(idx > 0){
        soma += bit[idx];
        idx -= idx & (-idx);
    }
    return soma;
}


void dfsC(int v, vector<int>& ans, vector<vector<int>>& owns, vector<int>& idade){

    for(auto o : owns[v]){
        updateBIT(o, 1);
    }
    ans[v] = queryBIT(idade[v]+1);
    for(auto u: filhos[v]){
        dfsC(u, ans, owns, idade);
    }

    for(auto o : owns[v]){
        updateBIT(o, -1);
    }
}

void dfs(int s){
    for(int i=0;i<filhos[s].size();i++){
        int f = filhos[s][i];
        if(memo[0][s] == f) continue;
        depth[f] = depth[s]+1;
        memo[0][f] = s;
        dfs(f);
    }
}

void compute(int n){
    for(int passos = 1;passos<LN;passos++){
        for(int i=0;i<n;i++){
            memo[passos][i]=memo[passos-1][memo[passos-1][i]];
        }
    }
}

int walk(int s, int dis){
    int jump = 0;
    while(dis){
        if(dis&1) s=memo[jump][s];
        jump++;
        dis>>=1;
    }
    return s;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> idades(n);
    for(int i=0;i<n;i++){
        int a, from; 
        cin >> a >>from;
        from--;
        if(i) filhos[from].push_back(i);
        idades[i] = a;
    }
    vector<pair<int,pair<int,int>>> festas;
    for(int i=0;i<m;i++){
        int o, l, r;
        cin >> o >> l >> r;
        o--;
        festas.push_back({o, {l,r}});
    }
    buildBIT();
    dfs(0);
    compute(n);
    vector<vector<int>> owns(n);
    for(int i=0;i<m;i++){
        int s = festas[i].first;
        int b = 20;
        int r = festas[i].second.second;
        for(int b = LN-1; b >= 0; b--){
            int u = memo[b][s];
            if(idades[u] <= r)
                s = u;
        }
        owns[s].push_back(festas[i].second.first);
    }
    vector<int> ans(n, 0);
    dfsC(0, ans, owns, idades);
    for(int i=0;i<ans.size();i++){
        if(i) cout << " ";
        cout << ans[i];
    }

    cout << endl;

    return 0;
}