class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y, cnt = 0;
        while (z) {
            if (z & 1)
                cnt++;
            z >>= 1;
        }
        return cnt;
    }
};
