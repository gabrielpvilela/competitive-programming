#include <bits/stdc++.h>
using namespace std;

int main() {


    int a, b, c;
    cin >> a >> b >> c;
    int a1, b1, c1;
    cin >> a1 >> b1 >> c1;
    int soma = 0;
    if(a1 > a) soma += (a1 - a);
    if(b1 > b) soma += (b1 - b);
    if(c1 > c) soma += (c1 - c);
    
    cout << soma << endl;


    return 0;
}