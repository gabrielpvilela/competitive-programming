#include<bits/stdc++.h>
using namespace std;
int main(){

    long long int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        vector<long long int> torres(n);
        for(long long int i=0;i<n;i++){
            cin >> torres[i];
        }
        long long int mov = 0;
        for(long long int i=n-2;i>=0;i--){
            if(torres[i] > torres[i+1]){
                mov+=torres[i] - torres[i+1];
                torres[i] = torres[i+1];
            }
        }
        // for(auto t : torres) cout<< t << " ";
        // cout << endl;
        long long int maior = 1;
        long long int atual = 1;
        for(long long int i=1;i<n;i++){
            if(torres[i] == torres[i-1]){
                atual++;
            }else{
                atual = 1;
            }
            maior = max(maior, atual);
        }
        cout << mov + maior - 1 << endl;
    }

    return 0;
}