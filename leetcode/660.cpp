#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
class Solution {
public:
    bool check(long long x) {
        while (x) {
            if (x % 10 == 9) return true;
            x /= 10;
        }
        return false;
    }
    int newInteger(int n) {
        long long ret = 1;
        while (n) {
            if (!check(ret++)) { n--;}
        }
        return ret - 1;
    }
};

int main() {
    Solution s;
    cout<<s.newInteger(100000000);
    return 0;
}




