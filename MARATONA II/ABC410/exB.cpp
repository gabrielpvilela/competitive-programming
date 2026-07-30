#include<bits/stdc++.h>
using namespace std;
int main(){

    int n, q;
    cin >> n >> q;
    vector<int> caixas(n, 0);
    vector<int> ans;
    int q1 = q;
    while(q--){
        int v;
        cin >> v;
        v--;
        if(v>=0){
            caixas[v]++;
            ans.push_back(v);
        }else{
            pair<int,int> vPos = {caixas[0], 0};
            for(int i=1;i<n;i++){
                if(caixas[i] < vPos.first){
                    vPos = {caixas[i], i};
                }
            }
            caixas[vPos.second]++;
            ans.push_back(vPos.second);
        }
    }
    for(int i=0;i<q1;i++){
        if(i) cout << " ";
        cout << ans[i]+1;
    }
    cout << endl;


    return 0;
}