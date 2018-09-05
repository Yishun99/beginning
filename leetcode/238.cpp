class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int tmp = 1;
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            tmp *= nums[i-1];
            res[i] = tmp;
        }
        for (int i = nums.size() - 2, tmp = 1; i >= 0; i--) {
            tmp *= nums[i+1];
            res[i] *= tmp;
        }
        return res;
    }
};
