#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<long long,long long>, bool>& p1, pair<pair<long long,long long>, bool>& p2){
    return p1.first.second < p2.first.second;
}

int main(){

    long long n, m ,k;
    cin >> n >> m >> k;
    vector<pair<pair<long long,long long>, bool>> nums(n); //cor, valor, usado

    vector<long long> maiorDeCada(n+1, -1); //pos do maior
    for(long long i=0;i<n;i++){
        cin >> nums[i].first.first >> nums[i].first.second;
        nums[i].second = false;
        if(maiorDeCada[nums[i].first.first] == -1) maiorDeCada[nums[i].first.first] = i;
        else if(nums[i].first.second > nums[maiorDeCada[nums[i].first.first]].first.second){
            maiorDeCada[nums[i].first.first] = i;
        }
    }
    vector<pair<long long,long long>> vals;
    long long total = 0;
    for(long long i=1;i<n+1;i++){
        if(maiorDeCada[i] != -1){
            vals.push_back({nums[maiorDeCada[i]].first.second, i});
            //nums[maiorDeCada[i]].first.second = 0;
        }
    }
    sort(vals.rbegin(), vals.rend());
    for(long long i=0;i<k;i++){  
        total+=vals[i].first;
        nums[maiorDeCada[vals[i].second]].first.second = 0;
    }

    sort(nums.rbegin(), nums.rend(), cmp);
    for(long long i=0;i<m-k;i++){
        total+=nums[i].first.second;
    }
    cout << total << endl;

    return 0;
}