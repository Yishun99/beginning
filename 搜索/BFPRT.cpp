#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;

const int maxn=10000 + 10;
int dp[maxn], a[maxn];
// dp[i] = max(dp[i-1] + a[i], a[i])

int kth(int a[], int l, int r, int id) {
    if (r - l + 1 <= 5) {
        insertionSort(a, l, r); return a[l + id - 1];
    }
    int t = l - 1; //当前替换到前面的中位数的下标
    for (int st = l, ed; (ed = st + 4) <= r; st += 5) {
        insertionSort(a, st, ed);
        t++; swap(a[t], a[st+2]);
    }
    int pivotId = (l + t) >> 1;
    BFPRT(a, l, t, pivotId-l+1);
    int m = partition(a, l, r, pivotId), cur = m - l + 1;
    if (id == cur) return a[m];                   //刚好是第id个数
    else if(id < cur) return BFPRT(a, l, m-1, id);//第id个数在左边
    else return BFPRT(a, m+1, r, id-cur);         //第id个数在右边

}



int partition(int a[], int l, int r, int pivotId) //对数组a下标从l到r的元素进行划分

{

    //以pivotId所在元素为划分主元

    swap(a[pivotId],a[r]);

    int j = l - 1; //左边数字最右的下标

    for (int i = l; i < r; i++)

        if (a[i] <= a[r])

            swap(a[++j], a[i]);

    swap(a[++j], a[r]);

    return j;

}


int main()
{
    string str;
    int tmp = 0, cnt = 0, k;
    getline(cin, str);
    stringstream iss(str);
    while (iss >> tmp) {
        a[cnt++] = tmp;
    }
    cin>>k;
    cout<<kth(a, cnt, k)<<endl;
    return 0;
}

