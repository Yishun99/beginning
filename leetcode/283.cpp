#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i])
                nums[j++] = nums[i];
        for (; j < nums.size(); j++)
            nums[j] = 0;
    }
};

int main() {
    Solution s;
    vector<int> vt = {1,0,3,0,1,2,0};
    s.moveZeroes(vt);
    for (int i = 0; i < vt.size(); i++) {
        cout<<vt[i]<<" ";
    }
    return 0;
}


































