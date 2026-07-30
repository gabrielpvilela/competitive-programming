#include<bits/stdc++.h>
using namespace std;

bool teste(vector<int> &p){
    set<int> found;
    found.insert(p[0]);
    for(int i=1;i<p.size();i++){
        if(found.count(p[i]) && p[i] != p[i-1]) return false;
        found.insert(p[i]);
    }
    return true;
}

bool solve(vector<int> p, int bE1, int bD1, int bE2, int bD2){

    vector<int> bordas = {bE1, bD1, bE2, bD2};

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(j==i) continue;
            if(bordas[j]) {
                swap(p[bordas[i]], p[bordas[j]-1]);
                if(teste(p)) return true;
                swap(p[bordas[i]], p[bordas[j]-1]);
            }
            if(bordas[j] < p.size()-1){
                swap(p[bordas[i]], p[bordas[j]+1]);
                if(teste(p)) return true;
                swap(p[bordas[i]], p[bordas[j]+1]);
            } 
        }
    }
    return false;
}

int main(){

    long long t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> prateleira(n);
        for(int i=0;i<n;i++){
            cin >> prateleira[i];
        }
        set<int> found;
        set<int> errors;
        found.insert(prateleira[0]);
        for(int i=1;i<n;i++){
            if(found.count(prateleira[i]) && prateleira[i] != prateleira[i-1]) errors.insert(prateleira[i]);
            found.insert(prateleira[i]);
        }
        bool deuCerto = false;
        if(errors.size() == 0) {cout << "YES" << endl; continue;}
        if(errors.size() > 2) {cout << "NO" << endl; continue;}
        for(auto nu : errors){
            //cout << nu << endl;
            int bordaEsqPrimBloco = -1, bordaDirPrimBloco = -1;
            int bordaEsqSegBloco = -1, bordaDirSegBloco = -1;
            for(int i=0;i<n;i++){
                if(prateleira[i] == nu){
                    int posEsq = i;
                    int aux = i;
                    while(i<n && prateleira[i] == nu) i++;
                    int posDir = i-1;;
                
                    if(bordaEsqPrimBloco == -1){
                        bordaEsqPrimBloco = posEsq;
                        bordaDirPrimBloco = posDir;
                    }else{
                        bordaEsqSegBloco = posEsq;
                        bordaDirSegBloco = posDir;
                    }
                }
            }
            //cout << bordaEsqPrimBloco << " " << bordaDirPrimBloco << " " << bordaEsqSegBloco << " " << bordaDirSegBloco << endl;
            if(solve(prateleira, bordaEsqPrimBloco, bordaDirPrimBloco, bordaEsqSegBloco, bordaDirSegBloco)){
                cout << "YES" << endl;
                deuCerto = true;
                break;
            }
        }
        if(!deuCerto)cout << "NO" << endl;
    }

    return 0;
}