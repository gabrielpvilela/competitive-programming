#include<bits/stdc++.h>
using namespace std;

int main(){

    
    int n, q;
    cin >> n >> q;
    vector<pair<int,int>> baladas(n);
    for(int i=0;i<n;i++){
        cin >> baladas[i].first >> baladas[i].second;
    }

    vector<int> nxt(n, -2);
    for(int i=n-2; i>=0;i--){
        if(baladas[i].second == baladas[i+1].second) nxt[i] = nxt[i+1];
        else nxt[i] = i+1;
    }

    // for(int i=0;i<n;i++){
    //     cout << nxt[i] << " ";
    // }cout << endl;

    vector<pair<int,int>> queries;
    for(int i=0;i<q;i++){
        int c, s;
        cin >> c >> s;
        queries.push_back({c,s});
    }
    for(int i=0;i<q;i++){
        int l = 0, r = n-1;
        int mid = (l+r)/2;
        int ans = -1;
        int custo = queries[i].first;
        while(l<=r){
            mid = (l+r)/2;
            
            if(custo < baladas[mid].first){
                l = mid+1;
            }else{
                r = mid-1;
                ans = mid;
            }
            
        }
        if(ans == -1) cout << "-1" << endl;
        else{
            int estilo = queries[i].second;
            if(estilo == baladas[ans].second) cout << nxt[ans]+1 << endl;
            else cout << ans+1 << endl;
        }
    }


    return 0;
}