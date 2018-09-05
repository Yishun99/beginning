class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, len = nums.size();
        for (int i = 0; i < k; i++)
            sum += nums[i];
        int mx = sum;
        for (int i = 0, j = k; j < len; i++, j++) {
            sum = sum - nums[i] + nums[j];
            mx = max(mx, sum);
        }
        return mx / (double)k;
    }
};
