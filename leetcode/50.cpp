#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1.0;
        long long nn = n;
        if (nn < 0) { nn *= -1; x = 1/x; }
        while (nn) {
            if (nn & 1)
                ret *= x;
            x *= x;
            nn >>= 1;
        }
        return ret;
    }
};


int main() {
    Solution s;
    cout<<s.myPow(10,-2);
    return 0;
}
