class Solution {
public:
    int sum = 0;
    int vis[105][105];
    int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    sum = 4;
                    dfs(i, j, grid);
                    return sum;
                }
            }
        }
        return sum;
    }
    void dfs(int x, int y, vector<vector<int>>& grid) {
        vis[x][y] = 1;
        int h = grid.size(), w = grid[0].size(), cnt;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny] && grid[nx][ny]) {
                cnt = 0;
                for (int j = 0; j < 4; j++)
                    if (nx + dir[j][0] >= 0 && ny + dir[j][1] >= 0 && vis[nx + dir[j][0]][ny + dir[j][1]]) cnt++;
                sum += 4 - 2 * cnt;
                dfs(nx, ny, grid);
            }
        }
    }
};






















class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0, repeat = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                cnt++;
                if (i)
            }
        }

    }
};



















class Solution {
public:
    int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int sum = 0, h = grid.size(), w = grid[0].size();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j]) {
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dir[k][0],  nj = j + dir[k][1];
                        if (ni < 0 || ni >= h) sum++;
                        else if (nj < 0 || nj >= w) sum++;
                        else if (!grid[ni][nj]) sum++;
                    }
                }
            }
        }
    }
};







