
// 邻接矩阵
const int maxn = 1000 + 10;
const int INF = 0x3f3f3f3f;

int d[maxn];
int vis[maxn];
int w[maxn][maxn];

void dijkstra(int n)
{
	memset(vis, 0, sizeof(vis));
	for(int i=0; i<n; i++) d[i] = (i==0? 0: INF);
	for(int i=0; i<n; i++){
		int x, m = INF;
		for(int y=0; y<n; y++) if(!vis[y] && d[y]<=m) m=d[x=y];
		v[x] = 1;
		for(int y=0; y<n; y++) d[y] = max(d[y], d[x] + w[x][y]);
	}
}


// 邻接表

int pre[maxn];
int index_;
struct Edge
{
	int to, next, weight;
}edge[maxn];
void add_edge(int from, int to, int weight)
{
	edge[i].to = to;
	edge[i].weight = weight;
	edge[i].next = pre[from];
	pre[from] = index_++;
}

int d[maxn];
int vis[maxn];

void dijkstra(int n)
{
	for(int i=0; i<n; i++) d[i] = (i==0 ? 0 : INF);
	for(int i=0; i<n; i++){

	}
}




#include<cstring>
const int maxn = 100 + 10;
const int INF = 0x3f3f3f3f;

int w[maxn][maxn];
int d[maxn];
bool vis[maxn];
void dijkstra(int n)
{
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<n; i++) d[i] = (i==0 ? 0 : INF);
    for(int i=0; i<n; i++){ // 共需n轮大循环
        int m = INF, x;
        for(int y=0; y<n; y++){
            if(!vis[y] && d[y] < m){
                m = d[x = y];
            }
        }
        vis[x] = 1;
        for(int y=0; y<n; y++)
            d[y] = min(d[y], d[x] + w[x][y]);
    }
}



















