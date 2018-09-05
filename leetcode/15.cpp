#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> fun(int a, int b, int c) {
        vector<int> ret;
        int t;
        if(a>b) {t=a; a=b; b=t;}
        if(b>c) {t=b; b=c; c=t;}
        if(a>b) {t=a; a=b; b=t;}
        ret.push_back(a);
        ret.push_back(b);
        ret.push_back(c);
        return ret;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> ret;
        vector<int> t;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp.insert(pair<int, int>(0 - nums[i], i));
        }
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<nums.size(); j++) {
                if(i!=j && mp.find(nums[i] + nums[j]) != mp.end()) {
                    int k = mp[nums[i] + nums[j]];
                    if(i != k && j != k){
                        t = fun(nums[i], nums[j], nums[k]);
                        ret.insert(t);
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(set<vector<int>>::iterator iter = ret.begin(); iter != ret.end(); iter++) {
            ans.push_back(*iter);
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}
