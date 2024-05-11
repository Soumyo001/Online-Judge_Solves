#include <bits/stdc++.h>
using namespace std;
namespace Hash{
    const int N=1e5+5;
    int hash_T[N];
    int __hashfunction(int x, int size, int i = 0){
        return (((x + 2) % size) + i) % size;
    }
    void __insert(int x, int size){
        if (hash_T[__hashfunction(x, size)] == 0){
            hash_T[__hashfunction(x, size)] = x;
            return;
        }
        int i = 1;
        while (true){
            if (i >= size){
                cout << "No space left" << endl;
                break;
            }
            if (hash_T[__hashfunction(x, size, i)] == 0){
                hash_T[__hashfunction(x, size, i)] = x;
                return;
            } else i++;
        }
    }
    int __search(int key,int size){
        if(hash_T[__hashfunction(key,size)]==key) return key;
        int i=1;
        while(true){
            if(i>=size) return -1;
            if(hash_T[__hashfunction(key,size,i)]==key) return key;
            else i++;
        }
        return -1;
    }
}
int main(void)
{
    int n;
    cin >> n;
    while (true)
    {
        int a;
        cin >> a;
        if (a == -1) break;
       Hash::__insert(a,n);
    }
    while(true){
        int a;cin>>a;
        if(a==-1) break;
        cout<<Hash::__search(a,n)<<endl;
    }
    for(int i=0;i<n;i++) cout<<Hash::hash_T[i]<<" ";
}
