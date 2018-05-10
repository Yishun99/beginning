#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;

const int maxn = 10000 + 10;

int vis[maxn];
int step[maxn];
int fa[maxn];
queue<int> q;
void bfs(int n, int k)
{
    memset(vis, 0, sizeof(vis));
    while(!q.empty())
        q.pop();
    vis[n]=1;
    step[n]=0;
    q.push(n);
    while(!q.empty()) {
        int now = q.front();
        int next[4];
        next[0] = now - 1;
        next[1] = now + 1;
        next[2] = 2 * now;
        for(int i=0; i<3; i++){
            if(!vis[next[i]] && next[i]>=0 && next[i]<=10000){
                q.push(next[i]);
                vis[next[i]] = 1;
                step[next[i]] = step[now] + 1;
                fa[next[i]] = now;
                if(next[i] == k) {
                    return;
                }
            }
        }
        q.pop();
    }
}

int main()
{
    int n=37, k=9387;
    bfs(n, k);
    cout<<step[k]<<endl;

    stack<int> st;
    int i=k;
    st.push(k);
    while(fa[i] != n) {
        st.push(fa[i]);
        i = fa[i];
    }
    st.push(n);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}
