#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, k, b, count = 0;
        cin >> n >> k >> b;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (k == 1){
            for (int i = 0; i < n; i++)
                if (a[i] == b)
                    count++;
        }
                else if (k == 2){
                    for (int i = 0; i < n - 1; i++)
                        for (int j = i + 1; j < n; j++)
                            if (a[i] + a[j] == b)
                                count++;
                }
                            else if (k == 3){
                                for (int i = 0; i < n - 2; i++)
                                    for (int j = i + 1; j < n - 1; j++)
                                        for (int k = j + 1; k < n; k++)
                                            if (a[i] + a[j] + a[k] == b)
                                                count++;
                            }
        cout << "Case " << i << ": " << count << endl;
    }
}