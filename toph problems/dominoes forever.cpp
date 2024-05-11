#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(void)
{
    int n;
    cin >> n;
	ll v[10001],p[10001],a[10001],r=0;
    for (int i = 0; i < n; i++)
    {
		cin>>v[i];
    }
    for (int i = 0; i < n; i++)
    {
		cin>>p[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll q, coun = 1;
        cin >> q;
        ll mx=-1;
        for (int i = q - 1; i < n - 1 ; i++)
        {
            mx = max((v[i] + p[i]), mx);
            if (mx > p[i + 1])
                coun+=1;
            else
                break;
        }
        a[r]=coun;
        r++;
    }
    for(int i=0;i<r;i++) cout<<a[i]<<endl;
}
