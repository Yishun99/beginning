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
    int findPaths(int m, int n, int N, int i, int j) {
        long long dp[51][50][50] = {0};
        for(int Ni = 1; Ni<=N; Ni++)
        	for(int mi = 0; mi<m; mi++)
        		for(int ni = 0; ni<n; ni++)
        			dp[Ni][mi][ni] = ((mi == 0 ? 1 : dp[Ni - 1][mi - 1][ni]) + (mi == m - 1 ? 1 : dp[Ni - 1][mi + 1][ni]) + 
        							 (ni == 0 ? 1 : dp[Ni - 1][mi][ni - 1]) + (ni == n - 1 ? 1 : dp[Ni - 1][mi][ni + 1])) % 1000000007;
    	return dp[N][i][j];
    }
};

int main()
{
	
	return 0;
}