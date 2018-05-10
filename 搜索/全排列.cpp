#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 1000 + 10;

int t[maxn], vis[maxn];
int n, cnt;

void allRange(int cur) {
    if (cur > n) {
        cnt++;
        for (int i = 1; i <= n; i++) cout<<t[i]<<" ";
        cout<<endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            t[cur] = i;
            allRange(cur + 1);
            vis[i] = 0;
        }
    }
}


int main()
{
    while (cin>>n) {
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        allRange(1);
        cout<<n<<": "<<cnt<<endl;
    }
    return 0;
}




























