#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        vector<int> seis, dois, tres, outros;

        for(int i=0;i<n;i++){
            cin >> nums[i];
            if(nums[i]%2==0 && nums[i]%3==0) seis.push_back(nums[i]);
            else if(nums[i]%2==0){
                dois.push_back(nums[i]);
            }else if(nums[i]%3==0){
                tres.push_back(nums[i]);
            }else outros.push_back(nums[i]);
        }
        bool primeiro = true;
        for(int d : seis){
            if(!primeiro) cout << " ";
            cout << d;
            primeiro = false;
        }
        for(int d : dois){
            if(!primeiro) cout << " ";
            cout << d;
            primeiro = false;
        }
        for(int d : outros){
            if(!primeiro) cout << " ";
            cout << d;
            primeiro = false;
        }
        for(int d : tres){
            if(!primeiro) cout << " ";
            cout << d;
            primeiro = false;
        }
        cout << endl;
    }

    return 0;
}