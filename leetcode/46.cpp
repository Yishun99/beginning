class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        vector<int> vis(nums.size(), 0);
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

