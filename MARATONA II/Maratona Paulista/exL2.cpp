#include<bits/stdc++.h>
using namespace std;

//n n^2
//0 4 2 6 1 5 3
//0 1
//3 4 5 6
//memo[i][j] i é o indice esquerdo do vetor, e j o direito
//3 4 5 6
//4 6 5 3
//D D D X
//X D D E
//E D X E
//E X E E
//E E E E

//4 3 1 2 0
//D D D X D
//D D X E D

//2 0 1
//D X D
//E X D D E E 2
//E E X D E E 2, 1, 1, 2, 2, 3

const int NMAX = 507;

int memo[NMAX][NMAX];
int n;
int melhor(int l, int r, vector<int>& nums){

    if(l >= r) return 0;
    if(memo[l][r] != -1) return memo[l][r];
    
    int resp = -1;
    int tam = r-l+1;
    int cont = 0;
    vector<int> pos(r-l+1);
    string s;
    for(int i=0;i<n;i++){
        if(nums[i] <= r && nums[i] >= l) {pos[nums[i]-l] = cont++; s+='D';}
    }

    int ans = 0;
    for(int i=0;i<=r-l;i++){
        
        //int best = 0;

        s[pos[i]] = 'X';
        if(i) s[pos[i-1]] = 'E';
        
        if(pos[i]){
            if(s[pos[i] - 1] == 'E') ans--;
        }
        if(pos[i] < tam-1){
            if(s[pos[i]+1] == 'E') ans--;
        }
        if(pos[i] < tam-1 && pos[i]){
            if(s[pos[i]+1] != s[pos[i] - 1]) ans++;
        }//aviso

        if(i){
            if(pos[i-1] < tam-1 && pos[i-1]){
                if(s[pos[i-1]+1] != s[pos[i-1] - 1] && (s[pos[i-1] - 1] == 'E' || s[pos[i-1]+1] == 'E')) ans--;
            }
            if(pos[i-1]){
                if(s[pos[i-1] - 1] != 'E') ans++;
            }
            if(pos[i-1] < tam-1){
                if(s[pos[i-1]+1] != 'E') ans++;
            }
        }

        int mai = melhor(i+1+l, r, nums), men = melhor(l, i-1+l, nums);
        if(ans + mai + men > resp){
            resp = ans + mai + men;
        }
    }
    return memo[l][r] = resp;
}

int main(){

    //for(int i=0;i<500;i++) cout << i << " ";
    cin.tie(0);
    ios::sync_with_stdio(0);
    memset(memo, -1, sizeof memo);
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        //nums[i] = i;
        cin >> nums[i];
    }

    int resp = melhor(0, n-1, nums);
    cout << resp << endl;


    return 0;
}