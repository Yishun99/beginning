class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        vector<int> vis(nums.size(), 0);
        sort(nums.begin(), nums.end());
        backtrack(ret, nums, tmp, vis);
        return ret;
    }
    void backtrack(vector<vector<int>>& ret, vector<int>& nums, vector<int>& tmp, vector<int>& vis) {
        int len = nums.size();
        if (tmp.size() >= len) {
            ret.push_back(tmp);
            return;
        }
        for (int i = 0; i < len; i++) {
            ////when a number has the same value with its previous,
            //we can use this number only if his previous is used
            //相当于给他们排一个顺序，相同的数字就有了内部的相对顺序
            if (i > 0 && nums[i] == nums[i-1] && !vis[i-1]) continue;
            if (!vis[i]) {
                vis[i] = 1;
                tmp.push_back(nums[i]);
                backtrack(ret, nums, tmp, vis);
                tmp.pop_back();
                vis[i] = 0;
            }
        }
    }
};
