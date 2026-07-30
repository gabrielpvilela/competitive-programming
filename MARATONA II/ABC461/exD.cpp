#include<bits/stdc++.h>
using namespace std;

int op(int h1, int h2, int l, int r, vector<vector<int>>& mat){
    int h = mat.size();
    int w = mat[0].size();
    int ans = mat[h2][r];
    if(l-1 >= 0) ans -= mat[h2][l-1];
    if(h1 - 1 >= 0) ans -= mat[h1-1][r];
    if(l-1 >= 0 && h1 - 1 >=0) ans += mat[h1-1][l-1];
    return ans;
}

int main(){

    int h, w, k;
    cin >> h >> w >> k;
    vector<string> grid(h);
    for(int i=0;i<h;i++){
        cin >> grid[i];
    }
    vector<vector<int>> matPre(h, vector<int>(w));
    matPre[0][0] = (grid[0][0] == '1' ? 1 : 0);
    for(int i=1;i<h;i++){
        matPre[i][0] = matPre[i-1][0] + (grid[i][0] == '1' ? 1 : 0);
    }
    for(int i=1;i<w;i++){
        matPre[0][i] = matPre[0][i-1] + (grid[0][i] == '1' ? 1 : 0);
    }
    for(int i=1;i<h;i++){
        for(int j=1;j<w;j++){
            matPre[i][j] = matPre[i-1][j] + matPre[i][j-1] - matPre[i-1][j-1] + (grid[i][j] == '1' ? 1 : 0);
        }
    }
    long long ans = 0;
    vector<int> freq(h * w + 1, 0);

    for(int i=0;i<h;i++){
        for(int j=i;j<h;j++){
            freq[0] = 1;
            for(int col = 0; col < w; col++){
                int pref_sum = op(i, j, 0, col, matPre);

                if(pref_sum >= k){
                    ans += freq[pref_sum - k];
                }

                freq[pref_sum]++;
            }
            for(int col = 0; col < w; col++){
                int pref_sum = op(i, j, 0, col, matPre);
                freq[pref_sum]--;
            }
            freq[0] = 0;
        }
    }
    cout << ans << endl;

    return 0;
}