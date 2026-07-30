#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int m = 1;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 0; i < n; i++){
        int ans = 1;
        for(int j = i+1; j < n; j++){
            if(a[j] - a[j-1] <= x)
                ans++;
            else
                break;
        }
        m = max(ans, m);
    }
    cout << m << endl;
    return 0;
}