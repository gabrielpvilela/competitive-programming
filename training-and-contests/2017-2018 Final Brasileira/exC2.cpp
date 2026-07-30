#include<bits/stdc++.h>
using namespace std;
int main(){

    int k,n;
    cin >> k >> n;
    vector<pair<int,int>> conta(k, {0,-1});
    for(int i=0;i<k;i++){
        conta[i].second = i+1;
    }

    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        if(n==1){
            cout << "-" << aux << endl;
            return 0;
        }   
        aux--;
        conta[aux].first++;
    }
    sort(conta.begin(), conta.end());

    for(int i=2;i<k-1;i++){
        if(conta[i].first != conta[i-1].first){
            cout << "*" << endl;
            return 0;
        }
    }
    string ans = "";
    if(conta[k-1].first - conta[k-2].first > 1){
        cout << "*" << endl;
        return 0;
    }else if(conta[k-1].first - conta[k-2].first == 1){
        ans += "-" + to_string(conta[k-1].second);
        conta[k-1].first--;
    }

    if(conta[1].first - conta[0].first > 1){
        cout << "*" << endl;
        return 0;
    }else if(conta[1].first - conta[0].first == 1){
        if(ans!="") ans+=" ";
        ans += "+" + to_string(conta[0].second);
    }
    cout << ans << endl;

    return 0;
}