#include <bits/stdc++.h>
using namespace std;

int main() {

    int k, n;
    cin >> k >> n;
    vector<int> conta(k+1, 0);
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        conta[aux]++;
    }
    int menor = -1, meio = -1, maior = -1;
    bool deuRuim = false;
    for(int i=1;i<=k;i++){
        if(menor == -1){
            menor = conta[i];
        }
        else if(meio == -1 && menor != conta[i]){
            if(menor > conta[i]){
                meio = menor;
                menor = conta[i];
            }else{
                meio = conta[i];
            }
        }else if(maior == -1 && menor != conta[i] && meio != conta[i]){
            if(menor > conta[i] && meio > conta[i]){
                maior = meio;
                meio = menor;
                menor = conta[i];
            }else if(menor < conta[i] && meio > conta[i]){
                maior = meio;
                meio = conta[i];
            }else{
                maior = conta[i];
            }
        }else if(maior != -1 && meio != -1 && menor != -1 && maior != conta[i] && meio != conta[i] && menor != conta[i]){
            deuRuim = true;
            break;
        }
        
    }

    if(deuRuim){
        cout << "*" << endl;
    }else{
        if(maior == -1){
            int contameio = 0, contamenor = 0;
            for(int i=1;i<=k;i++){
                if(meio == conta[i]) contameio++;
                if(menor == conta[i]) contamenor++;
            }
            if(contamenor > 1 && contameio > 1){
                cout << "*" << endl;
                return 0;
            }
            if(contamenor > 1){
                cout << "-" << contameio << endl;
                return 0;
            }
            if(contameio > 1){  
                cout << "+" << contamenor << endl;
                return 0;
            }
            
        }
        else{
            int contameio = 0, contamenor = 0, contamaior;
            for(int i=1;i<=k;i++){
                if(meio == conta[i]) contameio++;
                if(menor == conta[i]) contamenor++;
                if(maior == conta[i]) contamaior++;
            }
            if(contamenor > 1|| contamaior > 1){
                cout << "*" << endl;
                return 0;
            }
            if(contamaior - contamenor > 2){
                cout << "*" << endl;
                return 0;
            }
            // if(contamaior > contamenor){
            //     maior = 
            // }
            cout << "-" << maior << " " << "+" << menor << endl;
        }
    }
    return 0;
}