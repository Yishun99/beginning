#include <iostream>
#include <vector>
#include <set>
#include<map>

using namespace std;

const int maxn = 100000;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len = nums.size();
        map<int, int> v1;
        vector<int> res;
        set<int> st;
        vector< vector<int> > v2(len + 2);
        for (int i = 0; i < len; i++) {
        	v1[nums[i]]++;
        }
        for (int i = 0; i < len; i++) {
        	if (st.find(nums[i]) == st.end())
        		v2[v1[nums[i]]].push_back(i + 1);
        	st.insert(nums[i]);
        }
        for (int i = len + 1; i >= 0 && k > 0; i--) {
        	for (int j = 0; j < v2[i].size() && k > 0; j++) {
        		res.push_back(nums[v2[i][j] - 1]);
        		k--;
        	}
        }
        return res;
    }
};



int main()
{
  	int myints[] = {2,1,1,1,2,2,3};
  	vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
	Solution s;
	vector<int> res = s.topKFrequent(v, 1);
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}