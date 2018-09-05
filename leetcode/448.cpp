class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> tmp(nums.size() + 1, 0), ret;
        for (int i = 0; i < nums.size(); i++)
            tmp[nums[i]] = 1;
        for (int i = 1; i < tmp.size(); i++)
            if (!tmp[i])
                ret.push_back(i);
        return ret;
    }
};
