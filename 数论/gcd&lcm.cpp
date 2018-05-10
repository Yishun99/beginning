#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int t;
    while(b > 0){
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int gcd2(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

//最小公倍数
//lcm = a*b/gcd(a,b)
int lcm(int a, int b) {
    return a*b/gcd(a, b);
}

int main()
{
    cout<<gcd2(18, 45)<<endl;
    cout<<lcm(18, 45);
    return 0;

}
