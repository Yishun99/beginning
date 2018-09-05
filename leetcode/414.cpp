class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> top;
        for (int i = 0; i < nums.size(); i++) {
            top.insert(nums[i]);
            if (top.size() > 3)
                top.erase(top.begin());
        }
        return top.size() == 3 ? *top.begin() : *top.rbegin();
    }
};
