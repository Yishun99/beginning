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
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
    	int sum = 0, maxdiff = INT_MIN;
    	for(vector<int> nut: nuts) {
    		int dist = abs(tree[0] - nut[0]) + abs(tree[1] - nut[1]);
    		sum += 2 * dist;
    		maxdiff = max(maxdiff, dist - abs(squirrel[0] - nut[0]) - abs(squirrel[1] - nut[1]));
    	}
    	return sum - maxdiff;
    }
};


int main()
{
	
	return 0;
}