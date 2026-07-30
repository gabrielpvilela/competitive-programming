#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    cin >> n >>  k;
    vector<int> jogadas(n);
    for(int i=0;i<n;i++){
        cin >> jogadas[i];
    }

    vector<bool> ganha(k+1, false);

    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(jogadas[j] > i) break;
            if(ganha[i - jogadas[j]] == false){
                ganha[i] = true;
                break;
            }
        }
    }
    if(ganha[k]) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}