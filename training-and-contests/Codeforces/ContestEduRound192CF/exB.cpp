#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool um = false, dois = false, tres = false;
        int umC = 0, doisC = 0;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        for(int i=0;i<n;i++){
            int aux = nums[i];
            if(!um){
                if(aux == 1) umC--;
                else umC++;
                if(umC <= 0){
                    um = true;
                    if(umC < 0 && i<n-1 && nums[i+1] == 3){i++;}
                }
            }else if(!dois){
                if(aux == 1 || aux == 2) doisC--;
                else doisC++;
                if(doisC <= 0) dois = true;
            }else{
                tres = true;
            }
        }
        if(um && dois && tres) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    //14 min 23 seg

    return 0;
}