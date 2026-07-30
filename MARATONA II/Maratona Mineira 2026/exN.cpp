#include<bits/stdc++.h>
using namespace std;
int maior = 0;
int movBx[] = {-2, -2, 2, 2};
int movBy[] = {2, -2, 2, -2};
int capX[] = {-1, -1, 1, 1};
int capY[] = {1, -1, 1, -1};
void dfs(vector<string>& grid, int x, int y, int lastX, int lastY, int n, int conta){
    //if(conta > maior) cout << lastX << " " << lastY << endl;
    maior = max(maior, conta);
    if(lastX != -1 && lastY != -1){ 
        grid[lastY][lastX] = '.';
    }else{
        grid[y][x] = '.';
    }
    for(int i=0;i<4;i++){
        if(x+movBx[i] < 0 || x+movBx[i] >= n || y+movBy[i] < 0 || y+movBy[i] >= n) continue;
        if(grid[capY[i]+y][capX[i]+x] == 'P' && grid[movBy[i]+y][movBx[i]+x] == '.'){
            dfs(grid, movBx[i]+x, movBy[i]+y, capX[i]+x, capY[i]+y, n, conta+1);
            grid[capY[i]+y][capX[i]+x] = 'P';
        }
    }
}

int main(){

    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin >> grid[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[j][i] == 'B'){ dfs(grid, i, j, -1, -1, n, 0); grid[j][i] = 'B';}
        }
    }
    cout << maior << endl;
}