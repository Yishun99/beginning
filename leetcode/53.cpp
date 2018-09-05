class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size(), dp = 0, maxSub = nums[0];
        for (int i = 0; i < len; i++) {
            dp = max(dp + nums[i], nums[i]);
            maxSub = max(maxSub, dp);
        }
        return maxSub;
    }
};
