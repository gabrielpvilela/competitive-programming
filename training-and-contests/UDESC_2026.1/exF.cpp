#include<bits/stdc++.h>
using namespace std;

int lis(vector<int>& arr){
    if(arr.empty()) return 0;

    vector<int> tails;
    tails.push_back(arr[0]);

    for(int i=1; i<arr.size();i++){
        int num = arr[i];

        if(num >= tails.back()){
            tails.push_back(num);
        }else{
            auto it = lower_bound(tails.begin(), tails.end(), num);
            *it = num;
        }
    }

    return tails.size();
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> lista(n);
    for(int i=0;i<n;i++){
        cin >> lista[i].first >> lista[i].second;
    }

    sort(lista.begin(), lista.end());
    vector<int> aux;
    for(int i=0;i<n;i++){
        aux.push_back(lista[i].second);
    }

    cout << lis(aux) << endl;


    return 0;
}