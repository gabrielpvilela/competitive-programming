#include<bits/stdc++.h>
using namespace std;

struct Line{
    long long a, b;
    Line(long long x, long long y) : a(x), b(y){}
    Line(){}
    long long f(long long x){
        return a*x + b;
    }
};
bool useless(Line L1, Line L2, Line L3) {
    return (double)(L3.b - L1.b) * (L1.a - L2.a) <= (double)(L2.b - L1.b) * (L1.a - L3.a);
}

void add_line(long long a, long long b, deque<Line>& dq) {
    Line L3 = {a, b};
    while (dq.size() >= 2 && useless(dq[dq.size()-2], dq.back(), L3)) {
        dq.pop_back();
    }
    dq.push_back(L3);
}


int main(){

    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];


    //dp[j] + b[j]*a[i];
    vector<long long> dp(n, 0);
    deque<Line> lines;
    lines.push_back(Line(b[0], dp[0]));
    for(int i=1;i<n;i++){
        Line frente;
        if(!lines.empty()){
            frente = lines.front();
            lines.pop_front();
        }
        while(!lines.empty() && frente.f(a[i]) > lines[0].f(a[i])){
            frente = lines.front();
            lines.pop_front();
        }
        lines.push_front(frente);
        dp[i] = lines[0].f(a[i]);
        add_line(b[i], dp[i], lines);
    }

    cout << dp[n-1] << endl;

    return 0;
}