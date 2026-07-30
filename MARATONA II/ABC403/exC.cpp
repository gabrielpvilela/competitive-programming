#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m, q;
    cin >> n >> m >> q;
    vector<bool> total(n, false);
    vector<set<int>> acesso(n);
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int x, y;
            cin >> x >> y;
            x--;
            acesso[x].insert(y);
        }else if(op == 2){
            int x;
            cin >> x;
            x--;
            total[x] = true;
        }else{
            int x, y;
            cin >> x >> y;
            x--;
            if(total[x] || acesso[x].count(y)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            } 
        }
    }


    return 0;
}