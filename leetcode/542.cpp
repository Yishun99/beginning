class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), maxn = row + col;
        vector<vector<int>> ret(row, vector<int>(col, maxn));
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (matrix[i][j] == 0)
                    ret[i][j] = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++){
                int top = (i - 1 >= 0) ? ret[i-1][j] : ret[i][j];
                int left = (j - 1 >= 0) ? ret[i][j-1] : ret[i][j];
                ret[i][j] = min(ret[i][j], min(top, left) + 1);
            }
        }
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                int down = (i + 1 < row) ? ret[i+1][j] : ret[i][j];
                int right = (j + 1 < col) ? ret[i][j+1] : ret[i][j];
                ret[i][j] = min(ret[i][j], min(down, right) + 1);
            }
        }
        return ret;
    }
};
