#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e6 + 2;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    vector<int> p(n), freq(NMAX, 0);
    for(int i=0;i<n;i++) {cin >> p[i]; freq[p[i]]++;}

    vector<vector<int>> divs(NMAX);
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j+= i) {
            divs[j].push_back(i);
        }
    }   

    vector<int> quant(NMAX, 0);

    for(int i=0;i<NMAX;i++){
        quant[freq[i]]++;
    }

    vector<int> resp(NMAX, 0);

    for(int i=0;i<NMAX;i++){
        for(int j=0;j<divs[freq[i]].size();j++){
            resp[divs[freq[i]][j]]++;
        }
    }
    // for(int i=0;i<n;i++) cout << freq[i] << " ";
    // cout << endl;
    // for(int i=0;i<n;i++) cout << quant[i] << " ";
    // cout << endl;
    // for(int i=0;i<100;i++) cout << resp[i] << " ";
    // cout << endl; 

    while(q--){
        int op;
        cin >> op;
        if(op == 1){

            int i, y;
            cin >> i >> y;
            i--;    
            int ant = p[i];
            int freqAnt = freq[ant];

            quant[freq[ant]]--;
            quant[freq[y]]--;
            for(int j=0;j<divs[freq[ant]].size();j++){
                resp[divs[freq[ant]][j]]--;
            }
            for(int j=0;j<divs[freq[y]].size();j++){
                resp[divs[freq[y]][j]]--;
            }


            freq[ant]--;
            freq[y]++;
            

            quant[freq[ant]]++;
            quant[freq[y]]++;
            for(int j=0;j<divs[freq[ant]].size();j++){
                resp[divs[freq[ant]][j]]++;
            }
            for(int j=0;j<divs[freq[y]].size();j++){
                resp[divs[freq[y]][j]]++;
            }

            p[i] = y;

        }else{
            int a;
            cin >> a;
            cout << resp[a] << endl;
        }
    }

    return 0;
}