class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int x = 0, y = 0, tmp;
        for (int i = 0; i < len; i++) {
            tmp = y;
            y = max(x + nums[i], y);
            x = tmp;
        }
        return y;
    }
};
