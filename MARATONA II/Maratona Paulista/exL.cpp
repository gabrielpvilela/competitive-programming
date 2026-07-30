#include<bits/stdc++.h>
using namespace std;

int melhor(vector<int> nums){
    if(nums.size() <= 1) return 0;
    int resp = -1;
    int qual = -1;
    int menor = INT32_MAX, maior = -1;
    for(int i=0;i<nums.size();i++){
        
        int ant = -1;
        int best = 0;
        for(int j=0;j<nums.size();j++){
            maior = max(maior, nums[j]);
            menor = min(menor, nums[j]);
            if(j==i) continue;
            if(ant == -1){
                ant = nums[j];
                continue;   
            }
            if((ant < nums[i] && nums[j] > nums[i]) || (ant > nums[i] && nums[j] < nums[i])){
                best++;
            }
            ant = nums[j];
        }
        int meio = (menor+maior)/2;
        if(best == resp && abs(qual-meio) < abs(nums[i]-meio)){
            resp = best;
            qual = nums[i];
        }
        else if(best > resp){
            resp = best;
            qual = nums[i];
        }
    }
    vector<int> menores, maiores;
    for(int i=0;i<nums.size();i++){
        if(nums[i] < qual) menores.push_back(nums[i]);
        if(nums[i] > qual) maiores.push_back(nums[i]);
    }
    return resp + melhor(menores) + melhor(maiores);
}

int main(){

    //for(int i=0;i<500;i++) cout << i << " ";
    cin.tie(0);
    ios::sync_with_stdio(0);
    


    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    int resp = melhor(nums);
    cout << resp << endl;


    return 0;
}