#include<bits/stdc++.h>
using namespace std;
int* merg(int *ptr1, int *ptr2, int len1, int len2);
void print(int *mergeA, int len);
int main(void)
{

    int arr1[5]= {1,2,3,4,5};
    int arr2[5]= {6,7,8,9,10};
    int len1=sizeof(arr1)/sizeof(arr1[0]);
    int len2=sizeof(arr2)/sizeof(arr2[0]);
    int *arr;
    arr= merg(arr1, arr2, len1, len2);
    for(int i=0 ; i<len1+len2; i++)
        printf("%d ", *(arr+i));
}
int* merg(int *ptr1, int *ptr2, int len1, int len2)
{
    /*int mergeA[len1+len2],result;
    for(int i=0; i<len1; i++)
    {
        *(mergeA+i)=*(ptr1+i);
    }*/
    ptr1=(int *) realloc(ptr1,10*sizeof(int));
    int j=len1;
    for( int i=0; i<len2; i++)
    {
        *(ptr1+i+j)=*(ptr2+i);
    }

    //print (mergeA, 10);
    return ptr1;


}
void print(int *mergeA, int len)
{
    for(int i=0; i<len; i++)

        printf("%d memory address and value %d\n", (mergeA+i), *(mergeA+i));
}
