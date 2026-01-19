#include <iostream>

using namespace std;

int x,y;
int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/ gcd(a,b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>x>>y;
    cout<< gcd(x,y)<<"\n"<<lcm(x,y);

    return 0;
}