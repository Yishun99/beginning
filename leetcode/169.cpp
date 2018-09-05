class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (++cnt[nums[i]] > len / 2)
                return nums[i];
        }
    }
};
