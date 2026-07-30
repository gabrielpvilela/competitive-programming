#include<bits/stdc++.h>
using namespace std;

long long ans = 0;
bool vis[2001][2001];
long long n, m;
long long pre[2001][2001];

// void frente(int y, int x, int h, vector<string>& grid){

//     ans += h;
//     char c = grid[y][x];
//     if(x < m-1){
//         if(grid[y][x+1] == c) frente(y, x+1, h, grid);
//     }

// }

void desce(int y, int x, long long h, vector<string>& grid){
    vis[y][x] = true;
    char c = grid[y][x];
    if(x < m-1){
        if(grid[y][x+1] == c) ans += pre[y][x] * h;
    }
    if(y < n-1 && !vis[y+1][x]){
        if(grid[y+1][x] == c) desce(y+1, x, h+1, grid);
    }

}


int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);


    cin >> n >> m;
    
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin >> grid[i];
    memset(vis, 0, sizeof vis);
    memset(pre, 0, sizeof pre);
    for(int i=m-2;i>=0;i--){
        for(int j=0;j<n;j++){
            if(grid[j][i] == grid[j][i+1]) pre[j][i] = pre[j][i+1] + 1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]) desce(i, j, 0LL, grid);
        }
    }

    cout << ans << endl;

    return 0;
}