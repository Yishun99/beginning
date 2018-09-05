class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] == nums[j])
                    return nums[i];
            }
        }
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1) {
            int slow = nums[0], fast = nums[nums[0]];
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            fast = 0;
            while (fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};

