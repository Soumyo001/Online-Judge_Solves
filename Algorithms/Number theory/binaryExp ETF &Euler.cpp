#include <bits/stdc++.h>
#define ll long long
const int M = 1e9 + 7;
using namespace std;
int binExp(int a, ll b, int m)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a)%m;
        }
        a = (a * 1LL * a)%m;
        b = b >> 1;
    }
    return ans;
}
int32_t main(void)
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        //in case when M is prime then M-1 else M=M*(1-1/(all prime factors of M))
        cout << binExp(a, binExp(b, c, M - 1), M) << endl;
    }
}