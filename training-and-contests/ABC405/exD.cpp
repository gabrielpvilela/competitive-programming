#include<bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[]= {1, -1, 0, 0};

void bfs(vector<string>& grid, vector<pair<int,int>> exits){

    int c = exits.size();
    //vector<queue<pair<int,int>>> q(c);
    queue<pair<int,int>> q;
    for(int i=0;i<c;i++) q.push(exits[i]);
    
    int contaCheias = (1<<(c)) - 1;

    while(!q.empty()){
        
            pair<int,int> u = q.front();
            q.pop();
            int h = u.first, w = u.second;
            for(int j=0;j<4;j++){
                if(h + dy[j] < 0 || h + dy[j] >= grid.size() || w + dx[j] < 0 || w + dx[j] >= grid[0].size() || grid[h+dy[j]][w+dx[j]]!='.') continue;
                q.push({h+dy[j], w+dx[j]});
                switch(j){
                    case 0:
                        grid[h+dy[j]][w+dx[j]] = '^';
                        break;
                    case 1:
                        grid[h+dy[j]][w+dx[j]] = 'v';
                        break;
                    case 2:
                        grid[h+dy[j]][w+dx[j]] = '>';
                        break;
                    case 3:
                        grid[h+dy[j]][w+dx[j]] = '<';
                        break;
                }
            }
        
    }

}

int main(){

    int h, w;
    cin >> h >>w;

    vector<pair<int,int>> exits; //h, w
    vector<string> grid(h);
    for(int i=0;i<h;i++){
        cin >> grid[i];
        for(int j=0;j<w;j++){
            if(grid[i][j] == 'E') exits.push_back({i, j});
        }   
    }

    bfs(grid, exits);
    for(int i=0;i<h;i++){
        cout << grid[i] << endl; 
    }

    return 0;
}