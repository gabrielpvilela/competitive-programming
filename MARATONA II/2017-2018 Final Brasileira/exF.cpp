#include<bits/stdc++.h>
using namespace std;

const int NMAX = 100002;

long long BIT[NMAX];
void updateBIT(int tam, int index, long long valor){
    while(index<=tam){
        BIT[index] = max(valor, BIT[index]);
        index+= index&(-index);
    }
}

void buildBIT(){
    memset(BIT, 0, sizeof BIT);
}

long long queryBIT(int index){
    long long ans = 0;
    while(index > 0){
        ans = max(ans, BIT[index]);
        index -= index&(-index);
    }
    return ans;
}

int main(){

    int n;
    cin >> n;
    map<pair<long long,long long>, long long> m; 
    vector<pair<long long, pair<long long,long long>>> pessoas;
    for(int i=0;i<n;i++){
        long long b, f, d;
        cin >> b >> f >> d;
        m[{b,f}] += d;
    }
    vector<long long> forca;
    for(auto k : m){
        long long b = k.first.first, f = k.first.second, d = k.second;
        pessoas.push_back({b, {f, d}});
        forca.push_back(f);
    }


    sort(forca.begin(), forca.end());
    sort(pessoas.begin(), pessoas.end());
    for(int i=0;i<pessoas.size();i++){
        pessoas[i].second.first = -(lower_bound(forca.begin(), forca.end(), pessoas[i].second.first)-forca.begin() + 1);
    }
    buildBIT();
    sort(pessoas.begin(), pessoas.end());
    long long ans = 0;
    for(int i=0;i<pessoas.size();i++){
        if(queryBIT(-pessoas[i].second.first - 1)+pessoas[i].second.second > ans){
            ans =queryBIT(-pessoas[i].second.first - 1)+pessoas[i].second.second;
            
        }
        updateBIT(pessoas.size(),-pessoas[i].second.first, queryBIT(-pessoas[i].second.first - 1)+pessoas[i].second.second);
        //ns = max(ans, queryBIT(-pessoas[i].second.first - 1)+pessoas[i].second.second);
        
    }   
    cout << ans << endl;

    return 0;
}