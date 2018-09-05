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
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s;
        for(int i: candies) s.insert(i);
        return min(s.size(), candies.size()/2);
    }
};

int main()
{
	
	return 0;
}