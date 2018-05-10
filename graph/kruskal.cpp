#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxe = 1000 + 10;
const int maxn = 100 + 10;


int u[maxe], v[maxe], w[maxe];//边的两个端点及权重
int r[maxe];//存储边的下标值

int f[maxn];
int n, m; //点，边数量

bool cmp(const int i, const int j) { return  w[i] < w[j]; }
int find1(int x) { return f[x] == x ? x : f[x] = find1(f[x]); }
int kruskal()
{
    int cost = 0;
    for(int i=0; i<n; i++) f[i] = i;
    for(int i=0; i<m; i++) r[i] = i;
    sort(r, r + m, cmp);
    for(int i=0; i<m; i++){
        int e = r[i];
        int a = find1(u[e]), b = find1(v[e]);
        if(a != b){ f[a] = b; cost += w[e]; }
    }
    return cost;
}



int main()
{
    return 0;
}
