#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin>>t;
    while(t--){
        int a,b;
        std::cin>>a>>b;
        int diff=std::abs(a-b);
        int q=diff/10;
        int r=diff%10;
        if(r>0) q++;
        std::cout<<q<<std::endl;
    }
}