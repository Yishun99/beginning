class Solution {
public:
    int climbStairs(int n) {
        long long a = 1, b = 1;
        while(n--) {
            a = (b += a) - a;
        }
        return a;
    }
};
