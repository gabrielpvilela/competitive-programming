#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        vector<int> b(n);
        for(int i=0;i<n;i++) cin >> b[i];
        int um = 0;
        for(int i=0;i<n;i++){
            if(b[i] > a[i]){
                um = INT32_MAX;
                break;
            }
            um += a[i] - b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int dois = c;
        for(int i=0;i<n;i++){
            if(b[i] > a[i]){
                dois = INT32_MAX;
                break;
            }
            dois += a[i] - b[i];
        }
        int ans = min(um, dois);
        if(ans == INT32_MAX){
            cout << "-1" << endl;
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}