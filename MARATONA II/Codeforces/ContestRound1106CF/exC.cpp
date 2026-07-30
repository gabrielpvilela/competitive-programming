#include<bits/stdc++.h>
using namespace std;
long long ans; 
map<int, int> contaProf;
void solve(vector<bool>& vis, vector<int>& prof, vector<vector<int>>& adj, bool veioDeUm, int v, vector<vector<int>>& salv, vector<int>& dist){

    vis[v] = true;
    bool temUmfilho = (adj[v].size() == 1) ? true : false;
    //if(!veioDeUm) {ans += prof[v]; cout << v << ": " << prof[v] << endl;}
     
    if(contaProf[dist[v]] != 1 && !veioDeUm) {
        int val = salv[dist[v]][0] == prof[v] ? salv[dist[v]][1] : salv[dist[v]][0]; 
        ans+=min(prof[v],val);
        cout << v+1 << ": " << min(prof[v],val) << " " << prof[v] << " "<< val<< endl;
    }
    
        for(auto u: adj[v]){
        if(vis[u]) continue;
        solve(vis, prof, adj, temUmfilho, u, salv, dist);
    }

}

int dfs(int v, vector<int>& prof, vector<vector<int>>& adj, vector<int>& dist, vector<vector<int>>& quem){
    int atual;
    // quem[dist[v]].push_back(v);
    if(!adj[v].size()) atual = 0;
    else atual = 0; 
    for(auto u: adj[v]){
        if(prof[u]!=-1){
            atual = max(atual, prof[u]);
        }else{
            
            dist[u] = dist[v] + 1;
            atual = max(dfs(u, prof, adj, dist, quem), atual);
        }
    }

    quem[dist[v]].push_back(atual+1);
    contaProf[dist[v]]++;
    return prof[v] = atual+1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        ans = 0;
        contaProf.clear();
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        for(int i=1;i<n;i++){
            int v;
            cin >> v;
            v--;
            adj[v].push_back(i);
        }
        vector<bool> vis(n+1, false);
        vector<int> prof(n+1, -1);
        vector<int> dist(n+1, 0);
        vector<vector<int>> quemTemdist(n);
        dfs(0, prof, adj, dist, quemTemdist);
        vector<int> valPraCadaProf(n, -1);
        for(int i=0;i<n;i++){
            sort(quemTemdist.rbegin(), quemTemdist.rend());
            // int resp = INT32_MAX;
            // for(auto m:quemTemdist[i]){
            //     resp = min(resp, prof[m]);
            // }
            // valPraCadaProf[i] = resp;
        }
        for(int i=0;i<n;i++) cout << prof[i] << " ";
        cout << endl;
        solve(vis, prof, adj, false, 0, quemTemdist, dist);
        ans += prof[0];
        cout << ans << endl;
    }
    return 0;
}