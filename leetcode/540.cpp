class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;
        while (r - l > 2) {
            mid = (l + r) / 2;
            if (nums[mid] == nums[mid - 1]) {
                if (mid % 2 == 0) r = mid - 2;
                else l = mid + 1;
            }
            else if (nums[mid] == nums[mid + 1]) {
                if (mid % 2 == 0) l = mid + 2;
                else r = mid - 1;
            }
            else return nums[mid];
        }
        if (l == r) return nums[l];
        return nums[l] == nums[l + 1] ? nums[r] : nums[l];
    }
};
