#include<bits/stdc++.h>
using namespace std;

long long tri[55][55];

void pre(){
    tri[0][0] = 1;
    for(int i=1;i<55;i++){
        for(int j=0;j<=i;j++){
            long long ans = 0;
            if(j) ans+= tri[i-1][j-1];
            if(j!=i) ans += tri[i-1][j];
            tri[i][j] = ans;
        }
    }
}

long long calcula(long long n, vector<long long> nums, long long k){
    long long ans = 0;
    int tam = nums.size();
    
    for(int i=0;i<tam;i++){ 
        if(k==0){
            break;
        }
        if(nums[i] <=n){
            if(tam-i >= k)ans += tri[tam-i-1][k];
            k--;
            n-=nums[i];
        }
    }
    if(!k) ans++;
    return ans;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);
    
    pre();

    int n, k;
    cin >> n >> k;
    vector<long long> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    long long B, A;
    cin >> A >> B;
    sort(nums.rbegin(), nums.rend());
    long long b = calcula(B, nums, k);
    long long a = calcula(A-1, nums, k);    

    cout << b-a << endl;

    return 0;
}