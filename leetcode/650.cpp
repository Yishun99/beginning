#include<iostream>
#include<queue>
#include<cstring>
using namespace std;


class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        return bfs(n);
    }
    int vis[1010], step[1010], cp[1010];
    queue<int> q;
    int bfs(int n) {
        memset(vis, 0, sizeof(vis));
        while (!q.empty()) q.pop();
        vis[1] = 1;
        step[1] = 0;
        cp[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int now = q.front();
            int nx1 = now + cp[now], nx2 = now * 2;
            if (nx2 <= 1000) {
                step[nx2] = step[now] + 2;
                cp[nx2] = now;
                q.push(nx2);
                if (n == nx2) return step[nx2];
            }
            if (nx1 > 1 && nx1 <= 1000) {
                step[nx1] = step[now] + 1;
                cp[nx1] = cp[now];
                q.push(nx1);
                if (n == nx1) return step[nx1];
            }
            q.pop();
        }
        return -1;
    }
};
int main() {
    Solution s;
    //for (int i = 1; i <= 20; i++)
    //    cout<<s.minSteps(11*i)<<endl;

    cout<<s.minSteps(121);
}

