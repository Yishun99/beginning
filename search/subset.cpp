class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        backtrack(ret, tmp, nums, 0);
        return ret;
    }
    void backtrack(vector<vector<int>>& ret, vector<int>& tmp, vector<int>& nums, int start) {
        int len = nums.size();
        ret.push_back(tmp);
        for (int i = start; i < len; i++) {
            tmp.push_back(nums[i]);
            backtrack(ret, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
};



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int len = ret.size();
            for (int j = 0; j < len; j++) {
                ret.push_back(ret[j]);
                ret.back().push_back(nums[i]);
            }
        }
        return ret;
    }
};








