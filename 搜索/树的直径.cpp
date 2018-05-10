#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int maxn=30000;

int vis[maxn];
vector<int> g[maxn];
queue<int> q;
int step[maxn];

int bfs(int s,int &t)
{
    memset(vis, 0, sizeof(vis));
    memset(step, 0, sizeof(step));
    while(!q.empty()) q.pop();
    int ret = 0;
    vis[s] = 1;
    step[s] = 0;
    t = s;
    q.push(s);
    while(!q.empty()) {
        int now = q.front();
        int len = g[now].size();
        for(int i=0; i<len; i++) {
            int next = g[now][i];
            if(!vis[next]) {
                q.push(next);
                vis[next] = 1;
                step[next] = step[now] + 1;
                if(step[next] > ret) {
                    ret = step[next];
                    t = next;
                }
            }
        }
        q.pop();
    }
    return ret;
}

int main()
{
    int n, m, tmp;
    while(scanf("%d%d", &n, &m) != EOF) {
        memset(g, 0, sizeof(g));
        for(int i=2; i<=n+m; i++){
            scanf("%d", &tmp);
            g[i].push_back(tmp);
            g[tmp].push_back(i);
        }

        int t;
        tmp = bfs(1,t);
        cout<<bfs(t,t)<<endl;
    }
    return 0;
}


//求树的直径，两遍bfs
