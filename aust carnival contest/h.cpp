#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double n;
        double x;
        cin >> n;
        x = 100 * n / (100 - n);
        // double a=x-x*(n/100);
        cout << fixed << setprecision(6) << x << endl;
    }
    return 0;
}