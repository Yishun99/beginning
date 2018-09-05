#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int maxn = 1000 + 10;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
	    for(int i = 0; i < nums.size(); i++){
	        cout<<nums[i]<<" ";
	        ones = (ones ^ nums[i]) & ~twos;
	        twos = (twos ^ nums[i]) & ~ones;
	        cout<<ones<<" "<<twos<<endl;
	    }
	    return ones;
    }
};

int main()
{
	Solution s;
	vector<int> v {1,1,1,2,3,2,2};
	cout<<s.singleNumber(v)<<endl;
	return 0;
}