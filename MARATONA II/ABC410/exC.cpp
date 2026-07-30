#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    int in = 0;
    for(int i=0;i<n;i++){
        v[i] = i+1;
    }
    while(q--){
        int op;
        cin >> op;
        int p;
        switch(op){
            case 1:
                int x;
                cin >> p >> x;
                p--;
                v[(p+in)%n] = x;
                break;
            case 2:
                cin >> p;
                p--;
                cout << v[(p+in)%n] << endl;
                break;
            case 3:
                int k;
                cin >> k;
                in = (in + k)%n;
                break;
        }
    }
    return 0;
}