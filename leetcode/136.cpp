class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), ans=nums[0];
        for(int i=1; i<n; i++){
        	ans ^= nums[i];
        }
        return ans;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i=1; i<n; i++){
        	nums[0] ^= nums[i];
        }
        return nums[0];
    }
};

