class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int cnt = 0;
        backtrack(nums, s, 0, cnt, 0);
        return cnt;
    }
    void backtrack(vector<int>& nums, int s, int cur, int& cnt, int ans) {
        if (cur == nums.size()) {
            if (ans == s)
                cnt++;
            return;
        }
        backtrack(nums, s, cur + 1, cnt, ans + nums[cur]);
        backtrack(nums, s, cur + 1, cnt, ans - nums[cur]);
    }
};
