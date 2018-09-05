class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, shortest = 0;
        while (l < nums.size() - 1 && nums[l] <= nums[l + 1]) l++;
        while (r > 0 && nums[r] >= nums[r - 1]) r--;
        if (r > l) {
            int vmin = INT_MAX, vmax = INT_MIN;
            for (int i = l; i <= r; i++) if (nums[i] < vmin) vmin = nums[i];
            for (int i = l; i <= r; i++) if (nums[i] > vmax) vmax = nums[i];
            while (l >= 0 && nums[l] > vmin) l--;
            while (r <= nums.size() - 1 && nums[r] < vmax) r++;
            shortest = r - l - 1;
        }
        return shortest;
    }
};
