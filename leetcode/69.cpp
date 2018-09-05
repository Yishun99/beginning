#include<iostream>
#include<algorithm>
using namespace std;


class Solution {
public:
    double mySqrt(double x) {
        union {
            int i;
            float x;
        } u;
        u.x = (float)x;
        u.i = (1 << 29) + (u.i >> 1) - (1 << 22);
        return u.x;
    }
};

int main() {
    Solution s;
    //cout<<s.mySqrt(8);

    float a = 5.2;
    while(a) {
        if (a & 1) cout<<"1";
        else cout<<"0";
        a >>= 1;
    }

    return 0;
}
