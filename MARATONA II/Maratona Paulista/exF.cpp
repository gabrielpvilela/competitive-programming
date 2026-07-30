#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

struct point{
    int x, y;
    point(int x = 0, int y = 0): x(x), y(y){}
    point operator-(point q) const{return point(x-q.x, y-q.y);}
    double operator*(point q) const{return q.x*x + q.y*y;}
    double operator%(point q) const{return x*q.y - y*q.x;}
};
double EPS = 1e-10;
point p;
int n;
vector<vector<int>> adj(MAXN);
vector<double> ret(MAXN);
vector<point> pontos(MAXN);
vector<bool> vis(MAXN);

double angulo(point p, point q, point r){
    point u = p - q;
    point v = r - q;
    return atan2(u%v, u*v);
}

bool dfs(int v, int pai = -1){

    vis[v] = true;
    for(auto u : adj[v]){
        if(u == pai) continue;
        if(vis[u]) {
            if(ret[v] + angulo(pontos[v], p, pontos[u]) - ret[u] > EPS || ret[v] + angulo(pontos[v], p, pontos[u]) - ret[u] < -EPS) return true;
            continue;
        }
        ret[u] = ret[v] + angulo(pontos[v], p, pontos[u]);
        if(dfs(u, v)) return true;
    }
    return false;
}


bool compute(){
    for(int i=0;i<n;i++){
        ret[i] = 0;
        vis[i] = false;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            ret[i] = 0;
            if(dfs(i)) return true;
        }
    }
    return false;
}


int main(){

    int m;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> pontos[i].x >> pontos[i].y;
    }
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int k;
    cin >> k;
    string ans;
    for(int i=0;i<k;i++){

        cin >> p.x >> p.y;
        if(compute()) ans+='P';
        else ans+='G';

    }
    cout << ans << endl;
}