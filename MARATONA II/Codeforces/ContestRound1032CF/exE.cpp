#include<bits/stdc++.h>
using namespace std;

bool mat1[9][10];
string l, r;
void build1(int pos, bool tightUp, bool tightDown){

    if(pos >= r.length()) return;
    int high = tightUp ? r[pos] - '0' : 9;
    int low = tightDown ? l[pos] - '0' : 0;

    for(int i = low; i<= high;i++){
        if(mat1[pos][i]) return;
        mat1[pos][i] = true;
        bool newUp = tightUp && (i==high);
        bool newDown = tightDown && (i==low);
        build1(pos+1, newUp, newDown);
    }
}
// bool mat2[9][10]; //pos, digits
// void build2(){

// }

int main(){
    int t;
    cin >> t;
    while(t--){
        memset(mat1, 0, sizeof mat1);
        // memset(mat2, 0, sizeof mat2);
        cin >> l >> r;
        build1(0, true, true);
        int ans = 0;
        for(int i=0;i<r.size();i++){
            int conta = 3;
            for(int j=0;j<=9;j++){
                if(mat1[i][j]){
                    conta--;
                }
                conta = max(0,conta);
            }
            ans += conta;
        }
        cout << ans << endl;
    }
    return 0;
}