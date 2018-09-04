#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100+10;

int g[maxn][maxn],topo[maxn],c[maxn];
int n,m,t;
//c[u]=-1表示正在访问

bool dfs(int u)
{
    c[u] = -1;
    for(int v=1; v<=n; v++) {
        if(g[u][v]) {
            if(c[v] < 0) return false;
            else if(!c[v] && !dfs(v)) return false;
        }
    }
    c[u] = 1; topo[t--] = u;
    return true;
}

bool toposort()
{
    t = n;
    memset(c, 0, sizeof(c));
    for(int u=1; u<=n; u++){
        if(!c[u] && !dfs(u))
            return false;
    }
    return true;
}

int main()
{
    int tmp1, tmp2;
    while(scanf("%d%d",&n, &m) != EOF) {
        memset(g, 0, sizeof(g));
        memset(topo, 0, sizeof(topo));
        for(int i=1; i<=m; i++) {
            scanf("%d%d", &tmp1, &tmp2);
            g[tmp1][tmp2] = 1;
        }
        if(toposort()) {
            for(int i=1; i<=n; i++) {
                printf("%d", topo[i]);
                if(i!=n) printf(" ");
            }
            printf("\n");
        }
    }
}


