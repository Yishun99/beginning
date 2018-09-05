class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int row = a.size(), col = a[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        dp[0][0] = 1;
        if (row == 1 && col == 1 && a[0][0] == 1) return 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!a[i][j]) {
                    if (i > 0 && !a[i - 1][j]) dp[i][j] += dp[i - 1][j];
                    if (j > 0 && !a[i][j - 1]) dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[row - 1][col - 1];
    }
};
