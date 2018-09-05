#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

struct Node {
    int x;
    int y;
    Node(int xx, int yy) : x(xx), y(yy) {};
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> retMatrix(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                retMatrix[i][j] = bfs(matrix, i, j);
            }
        }
        return retMatrix;
    }

    int bfs(vector<vector<int>>& matrix, int i, int j) {
        int dir[4][2] = {0, -1, 0, 1, -1, 0, 1, 0};
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        vector<vector<int>> step(row, vector<int>(col, 0));
        queue<Node> q;
        while(!q.empty())
            q.pop();
        vis[i][j] = 1;
        if(matrix[i][j] == 0){
            step[i][j] = 0;
            return step[i][j];
        }
        q.push(Node(i, j));
        while(!q.empty()) {
            Node now = q.front();
            for(int l = 0; l < 4; l++) {
                int nx = dir[l][0] + now.x;
                int ny = dir[l][1] + now.y;
                if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                    if (!vis[nx][ny]) {
                        q.push(Node(nx, ny));
                        vis[nx][ny] = 1;
                        step[nx][ny] = step[now.x][now.y] + 1;
                    }
                    if(matrix[nx][ny] == 0)
                        return step[nx][ny];
                }
            }
            q.pop();
        }
    }
};



int main() {
    Solution s;
    int row = 3, col = 3;
    vector<vector<int>> mat{{0,0,1},
                            {0,1,1},
                            {1,1,1}};
    vector<vector<int>> ans = s.updateMatrix(mat);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << ans[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}
