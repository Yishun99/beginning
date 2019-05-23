/*
老师想知道从某某同学当中，分数最高的是多少，现在请你编程模拟老师的询问。当然，老师有时候需要更新某位同学的成绩.

输入描述:
输入包括多组测试数据。
每组输入第一行是两个正整数N和M（0 < N <= 30000,0 < M < 5000）,分别代表学生的数目和操作的数目。
学生ID编号从1编到N。
第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩
接下来又M行，每一行有一个字符C（只取‘Q’或‘U’），和两个正整数A,B,当C为'Q'的时候, 表示这是一条询问操作，他询问ID从A到B（包括A,B）的学生当中，成绩最高的是多少
当C为‘U’的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。

输出描述:
对于每一次询问操作，在一行里面输出最高成绩.

输入例子1:
5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5

输出例子1:
5
6
5
9
*/


#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 30000 + 10;

struct node {
    int l,r,n;
} a[N<<2];


int n, m, s[N];

void build(int l, int r, int k) {
    a[k].l = l, a[k].r = r;
    if (l == r) {
        a[k].n = s[l];
        return;
    }
    int mid = (l + r)>>1;
    build(l, mid, k<<1);
    build(mid + 1, r, k<<1|1);
    a[k].n = max(a[k<<1].n, a[k<<1|1].n);
}

int query(int l, int r, int k) {
    if(a[k].l == l && a[k].r == r)
        return a[k].n;
    int mid = (a[k].l + a[k].r)>>1;
    if(l > mid) return query(l, r, k<<1|1);
    if(r <= mid) return query(l, r, k<<1);
    return max(query(l, mid, k<<1), query(mid+1, r, k<<1|1));
}


int x, val;  // update s[idx] to val
void update(int k) {
    if (a[k].l == x && a[k].r == x) { a[k].n = val; return; }
    int mid = (a[k].l + a[k].r)>>1;
    if (x <= mid) update(k<<1);
    else update(k<<1|1);
    a[k].n = max(a[k<<1].n, a[k<<1|1].n);
}

int main() {
    char t;
    int t1, t2;
    freopen("data", "r", stdin);
    while(cin>>n>>m){
        for (int i = 1; i <= n; i++) {
            cin>>s[i];
        }
        build(1, n, 1);
        while(m--) {
            cin>>t>>t1>>t2;
            if (t == 'Q') {
                cout<<query(min(t1, t2), max(t1, t2), 1)<<endl;
            } else {
                x = t1, val = t2;
                update(1);
            }
        }
    }
    return 0;
}


