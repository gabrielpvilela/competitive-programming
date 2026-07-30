#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Estrutura clássica de aresta para o Dinic
struct Edge {
    int to;
    int cap;
    int flow;
    int rev;
};

struct Dinic {
    int n;
    vector<vector<Edge>> adj;
    vector<int> level;
    vector<int> ptr;

    Dinic(int n) : n(n), adj(n), level(n), ptr(n) {}

    // Para grafos não direcionados, adicionamos capacidade em ambas as direções
    void add_edge(int from, int to, int cap) {
        adj[from].push_back({to, cap, 0, (int)adj[to].size()});
        adj[to].push_back({from, cap, 0, (int)adj[from].size() - 1});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& edge : adj[v]) {
                if (edge.cap - edge.flow > 0 && level[edge.to] == -1) {
                    level[edge.to] = level[v] + 1;
                    q.push(edge.to);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int v, int t, int pushed) {
        if (pushed == 0) return 0;
        if (v == t) return pushed;
        for (int& cid = ptr[v]; cid < adj[v].size(); ++cid) {
            auto& edge = adj[v][cid];
            int tr = edge.to;
            if (level[v] + 1 != level[tr] || edge.cap - edge.flow == 0) continue;
            int push = dfs(tr, t, min(pushed, edge.cap - edge.flow));
            if (push == 0) continue;
            edge.flow += push;
            adj[tr][edge.rev].flow -= push;
            return push;
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, t, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    int A1, A2, B1, B2;
    cin >> A1 >> A2 >> B1 >> B2;

    int src = 0;
    int dst = N + 1;

    Dinic d1(N + 2);
    for (auto& e : edges) {
        d1.add_edge(e.first, e.second, 1);
    }
    d1.add_edge(src, A1, INF);
    d1.add_edge(src, B1, INF);
    d1.add_edge(A2, dst, INF);
    d1.add_edge(B2, dst, INF);
    
    int ans1 = d1.max_flow(src, dst);

    Dinic d2(N + 2);
    for (auto& e : edges) {
        d2.add_edge(e.first, e.second, 1);
    }
    d2.add_edge(src, A1, INF);
    d2.add_edge(src, B2, INF);
    d2.add_edge(A2, dst, INF);
    d2.add_edge(B1, dst, INF);
    
    int ans2 = d2.max_flow(src, dst);

    cout << min(ans1, ans2) << "\n";

    return 0;
}