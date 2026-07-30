#include<bits/stdc++.h>
using namespace std;

int main(){
    
  string s;
  cin >> s;
  long long mod = 998244353;
  long long ans = 1;
  long long pa = 1;
  for(int i=1;i<s.size();i++){
    if(s[i] != s[i-1]){
      pa++;
    }else{
      pa = 1;
    }
    ans= (ans+pa)%mod;
  }
  cout << ans << endl;
  
  return 0;
}