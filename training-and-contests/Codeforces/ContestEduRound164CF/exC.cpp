#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        string a, b;
        string maior, menor;
        cin >> a >> b;
        bool ficouMaior = false;
        for(int i=0;i<a.size();i++){
            if(!ficouMaior){
                maior+=max(a[i], b[i]);
                menor+=min(a[i],b[i]);
                if(a[i] != b[i]) ficouMaior = true;
            }else{
                menor+=max(a[i], b[i]);
                maior+=min(a[i],b[i]);
            }
        }
        cout << maior << endl << menor << endl;
    }


    return 0;
}