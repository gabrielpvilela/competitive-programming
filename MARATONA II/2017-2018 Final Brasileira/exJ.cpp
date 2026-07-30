#include<bits/stdc++.h>
using namespace std;

bool funciona(long long int p, string s){
    // cout << p << endl;
    vector<long long int> vis(p, -1);
    for(long long int i=0;i<p;i++){
        long long int atual = i+p;  
        bool funfou = true;
        for(long long int j = i;j<s.size();j+=p){
            if(s[j] == 'P') funfou = false;            
        }
        if(funfou) return true;
    }
    return false;
}

int main() {

    string s;
    cin >> s;
    long long n = s.size();
    bool temP = false;
    for(long long int i=0;i<s.size();i++){
        if(s[i] == 'P'){
            temP = true;
            break;
        }
    }
    if(!temP){
        cout << n-1 << endl;
        return 0;
    }
    set<long long int> primos;
    for(long long i = 2; i*i<=n;i++){
        if(n%i==0) {primos.insert(i); if(i*i!=n) primos.insert(n/i);}
        // while(n%i==0){
        //     n/=i;
        // }
    }
    //
    if(n!=1 && n!=s.size()) primos.insert(n);
    vector<long long int> p2;
    for(auto p : primos){
        if(funciona(p, s)) p2.push_back(p); 
    }
    long long int conta = 0;
    for(long long int i=2;i<s.size();i++){
        long long int num = i;

        for(auto p : p2){
            if(num%p == 0){
                conta++;
                break;
            }
            //while(num%p == 0) num/=p; 
        }
        // if(num == 1) conta++;
    }
    cout << conta << endl;

    return 0;
}