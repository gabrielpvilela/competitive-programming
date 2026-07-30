#include <bits/stdc++.h>
using namespace std;

int solve(long long n, int b)
{
    long long res = 0;
    while (n)
    {
        res ^= (n % b);
        n /= b;
    }

    return res == 0;
}

int main()
{

    cin.tie(0);
    ios::sync_with_stdio(0);

    int res = 0;
    for (long long n = 1; n <= 1000000; n++)
    {
        int res = 0;
        for (long long b = 2; b <= n; b++)
            res += solve(n, b);
        // if (63 - __builtin_clzll(n - 1) != res)
        // if(1)
        // {
        //     cout << n << ": " << res << ' ' << 63 - __builtin_clzll(n - 1) << endl;
        // }
    }

    return 0;
}