#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn = 100 + 10;
const int maxe = 1000 + 10;


//貌似俗称链式前向星

int head[maxn], index_; //head[i] 表示顶点`i`的第一条边的数组下标，-1表示顶点`i`没有边
struct Edge{
    int to;
    int next;
}edge[maxe];
void addEdge(int from, int to)
{
    edge[index_].to = to;
    edge[index_].next = head[from]; //新增的边要成为顶点`from`的第一条边，而不是最后一条边
    head[from] = index_++; 
}


//print
int vis[maxn];
void dfs(int now)
{
    printf("%d ", now);
    for(int i=head[now]; i!=-1; i=edge[i].next){
        int next = edge[i].to;
        if(!vis[next]){
            vis[next] = 1;
            dfs(next);
        }
    }
}


int main()
{
    int e;
    while(scanf("%d", &e)!=EOF){
        memset(head, -1, sizeof(head));
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<e; i++){
            int from, to;
            scanf("%d %d", &from, &to);
            addEdge(from, to);
        }
        vis[0] = 1;
        dfs(0);
    }
    return 0;
}
