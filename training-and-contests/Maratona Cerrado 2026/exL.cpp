#include<bits/stdc++.h>
using namespace std;

bool solve(){

}

int main(){

    int n;
    cin >> n;
    int total = n + 2;
    bool achou = false;
    vector<int> caminho;
    caminho.push_back(1);
    for(int i=1;i<=n;i++){
        cout << "? " << caminho.back() + i << endl;
        int aux;
        cin >> aux;
        if(aux){
            caminho.push_back(caminho.back() + i);
        }else{
            caminho.push_back(caminho.back() + i + 1);
        }
    }

    int ini = 0, fim = caminho.size() - 1;
    int ans = -1;
    while(ini <= fim){
        int mid = (ini+fim)/2;

        cout << "? " << caminho[mid] << endl;
        int aux;
        cin >> aux;

        if(aux){
            ans = mid;
            ini = mid + 1;
        }else{
            fim = mid - 1;
        }
    }
    cout << "! " << caminho[ans] << endl;

    return 0;
}