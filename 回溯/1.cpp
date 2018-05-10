#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;

const int maxn=1000 + 10;
int n, a[maxn];
double mp[maxn][maxn];
double p, q;

double solve(int l, int r) {
    if (mp[l][r] != 0) return mp[l][r];
    if (l > r) return 0;
    if (l == r) return a[l];
    mp[l + 2][r] = solve(l + 2, r);
    mp[l + 1][r - 1] = solve(l + 1, r - 1);
    mp[l][r - 2] = solve(l, r - 2);
    return p * a[l] + (1 - p) * a[r] + p * q * mp[l + 2][r] + (p * (1 - q) + (1 - p) * q) * mp[l + 1][r - 1] + (1 - p) * (1 - q) * mp[l][r - 2];
}

int main()
{
    while (cin>>n>>p>>q) {
        memset(mp, 0, sizeof(mp));
        p = p / 100;
        q = q / 100;
        for(int i = 1; i <= n; i++) cin>>a[i];
        printf("%.3f\n", solve(1, n));
    }
    return 0;
}
