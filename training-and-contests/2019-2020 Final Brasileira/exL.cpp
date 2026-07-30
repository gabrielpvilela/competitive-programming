#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for(int i=0;i<n;i++){
        cin >> mat[i];
    }

    int ans = 1;

    vector<vector<int>> prefix(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        prefix[i][0] = 1;
        // else prefix[i][0] = {}
        for(int j=1;j<m;j++){
                if(mat[i][j] == mat[i][j-1])prefix[i][j] = prefix[i][j-1] + 1;
                else prefix[i][j] = 1;
            // else{
            //     int firstVal = (mat[i][j] == mat[i][j-1]) ? prefix[i][j-1] + 1 : 1;
            //     int secondVal = (firstVal >= prefix[i-1][j].first) ? prefix[i-1][j].second + 1 : 1;
            //     ans = max(ans, min(firstVal, secondVal));
            //     prefix[i][j] = {firstVal, secondVal};
            // }
        }
    }

    for(int i=1;i<m;i++){
        deque<pair<int,int>> dq;
        int start = 0, end = 0;
        
        while(end < n){
            while(!dq.empty() && dq.front().second < start){
                dq.pop_front();
                // cout << "1" << endl;
            }

            while(!dq.empty() && dq.back().first>=prefix[end][i]){//
                dq.pop_back();
                // cout << "2" << endl;
            }
            dq.push_back({prefix[end][i], end});
            end++;

            if(end - start <= dq.front().first){//
                ans = max(ans, end - start); // mudei front por end - start
            }else{
                while(end - start > dq.front().first){
                    start++;
                    while(!dq.empty() && dq.front().second < start){
                        dq.pop_front();
                        // cout << "3" << endl;
                    }
                    // cout << "4" << endl;
                }
            }
        }
        
    }
    cout << ans*ans << endl;
    return 0;
}