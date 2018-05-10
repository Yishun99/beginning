#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;

const int maxn=10000 + 10;
int dp[maxn], a[maxn];
// dp[i] = max(dp[i-1] + a[i], a[i])

int maxSublist(int a[],int n)
{
    memset(dp, 0, sizeof(dp));
    int m = dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + a[i], a[i]);
        if (dp[i] > m) m = dp[i];
    }
    return m;
}

int main()
{
    string str;
    int tmp = 0, cnt = 0;
    getline(cin, str);
    stringstream iss(str);
    while (iss >> tmp) {
        a[cnt++] = tmp;
    }
    cout<<maxSublist(a, cnt)<<endl;
    return 0;
}

