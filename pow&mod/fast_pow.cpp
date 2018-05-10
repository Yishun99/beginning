#include<iostream>
using namespace std;

int fast_pow(int x, int n) {//x^n
    int pw = 1;
    while (n > 0) {
        if (n & 1)
            pw *= x;
        x *= x;
        n >>= 1;
    }
    return pw;
}



int main()
{
    cout<<fib(6);
    return 0;
}

