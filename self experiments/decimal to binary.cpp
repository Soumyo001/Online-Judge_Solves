#include <bits/stdc++.h>
// #include <stdio.h>
// #include <string.h>
// #include <iostream>

using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // for (int i = 1; i <= 5; i++)
    // {
    int dec, bin = 0;
    cin >> dec;

    for (int j = 0; dec > 0; j++)
    {
        int rem = dec % 2;
        cout << "bin before: " << bin << endl;
        cout << "rem: " << rem << " j = " << j << endl;
        cout << "added" << rem * pow(10, j) << endl;
        bin = 0 + rem * pow(10, j);
        cout << "bin =" << bin << endl;

        dec /= 2;
    }

    cout << bin << endl;
    // cout << 0 + 1 * pow(10, 2);

    return 0;
}
