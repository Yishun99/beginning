#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ret;
        int len = nums.size(), t;
        for (int i = 0; i < len; i++) {
            t = target - nums[i];
            if (mp.find(t) != mp.end()) {
                ret.push_back(mp[t]);
                ret.push_back(i);
            }
            mp.insert(pair<int, int>(nums[i], i));
        }
        return ret;
    }
};

int main() {
    Solution s;
    int tmp[] = {0, 2, 4, 0};
    vector<int> nums(tmp, tmp + 4);
    vector<int> res;
    res = s.twoSum(nums, 4);
    cout<<res[0]<<res[1]<<endl;
    return 0;
}

