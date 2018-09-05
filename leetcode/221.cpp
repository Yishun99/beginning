class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = 0;
        if (row > 0) col = matrix[0].size();
        int dp[1010][1010];
        int mx = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i > 0 && j > 0 && matrix[i][j] == '1' && dp[i-1][j] > 0 && dp[i][j-1] > 0 && dp[i-1][j-1] > 0)
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                else dp[i][j] = matrix[i][j] - '0';
                if (dp[i][j] > mx) mx = dp[i][j];
            }
        }
        return mx * mx;
    }
};
