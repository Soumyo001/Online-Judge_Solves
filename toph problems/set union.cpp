#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,m,r=0;
    cin >> n >> m;
    int *f_n,*s_n,*r_n;
    f_n=new int[n];
    s_n=new int[m];
    r_n=new int[n+m];
    for(int i=0;i<n;i++)
        cin >> f_n[i];
    for(int i=0;i<m;i++)
        cin >> s_n[i];
    for (int i=0;i<n;i++)
    {
        r_n[r]=f_n[i];
        r++;
    }
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
              if(f_n[i]==s_n[j])
                  s_n[j]=-1;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(s_n[i]==-1)
            continue;
        else{
            r_n[r]=s_n[i];
            r++;
        }
    }
    sort(r_n,r_n+r);
    for(int i=0;i<r;i++)
    {
        if(i==0)
           cout << r_n[i];
        else{
            cout<< " "<<r_n[i];
        }
    }
    /*cout<<endl;
    delete[] r_n;
    for(int i=0;i<r;i++)
        cout<<" "<<r_n[i];*/
}
