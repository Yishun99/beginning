#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
int vis[55][55];
/*
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    	int row = grid.size(), col = grid[0].size();
    	int max = 0;
    	memset(vis, 0, sizeof(vis));
        for (int i = 0; i < row; i++) {
        	for (int j = 0; j < col; j++) {
        		if (grid[i][j] && !vis[i][j]) {
        			int res = 0;
        			dfs(grid, i, j, row, col, res);
        			max = res > max ? res : max;
        		}
        	}
        }
        return max;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int row, int col,  int& res) {
    	res++;
    	vis[x][y] = 1;
    	for (int i = 0; i < 4; i++) {
    		int nx = x + dir[i][0];
    		int ny = y + dir[i][1];
    		if (nx >= 0 && nx < row && ny >=0 && ny < col && grid[nx][ny] == 1 && !vis[nx][ny])
    			dfs(grid, nx, ny, row, col, res);
    	}
    }
};*/



int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
int vis[55][55];

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    	int row = grid.size(), col = grid[0].size();
    	int max = 0;
    	memset(vis, 0, sizeof(vis));
        for (int i = 0; i < row; i++) {
        	for (int j = 0; j < col; j++) {
        		if (grid[i][j] && !vis[i][j]) {
        			int res = dfs(grid, i, j, row, col);
        			max = res > max ? res : max;
        		}
        	}
        }
        return max;
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int row, int col) {
    	int res = 1;
    	vis[x][y] = 1;
    	for (int i = 0; i < 4; i++) {
    		int nx = x + dir[i][0];
    		int ny = y + dir[i][1];
    		if (nx >= 0 && nx < row && ny >=0 && ny < col && grid[nx][ny] == 1 && !vis[nx][ny])
    			res += dfs(grid, nx, ny, row, col);
    	}
    	return res;
    }
};
