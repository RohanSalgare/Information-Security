#include<iostream>
using namespace std;
int gcd(int a,int b){

    if(b>0){
        return gcd(b,a%b);
    }

    return a;
}
int main(){
    cout<<gcd(24,30);
    return 0;
}
