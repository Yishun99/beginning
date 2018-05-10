/*
0-1背包
有 N 件物品和一个容量为 V 的背包。放入第 i 件物品耗费的费用是 c_i ,得到
的价值是 c_i 。求解将哪些物品装入背包可使价值总和最大。

F[i][v] = max{F[i-1][v], F[i-1][v-c_i] + w_i

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1050;

int c[maxn],v[maxn];//cost and value
int dp[maxn][maxn];//dp[i][j]

void solve(int t, int m)
{
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=t; j++){
            if(j - c[i] >= 0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-c[i]] + v[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[m][t]<<endl;
}

int main()
{
    int t, m;//t:最大容量，m:物品数量
    while(scanf("%d%d",&t, &m)!=EOF){
        for(int i=1; i<=m; i++){
            scanf("%d%d", &c[i], &v[i]);
        }
        solve(t, m);
    }
    return 0;
}
