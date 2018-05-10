//最长不减序列
//3 2 2 5 3 6
//dp[i] = max{dp[j] | 0 <= j <= i && a[i] >= a[j]} + 1
#include<iostream>
#include<algorithm>
#include<cstring>
using  namespace std;

const int maxn = 100 + 10;
int d[maxn];

int longDec(int a[], int n){
    memset(d, 0, sizeof(d));
    int m=0;
    d[0]=1;
    for(int i=1;i<n;i++)
    {
        int s = 0;
        for(int j=0; j<i; j++){
            if(a[j] <= a[i] && s < d[j])
                s = d[j];
        }
        d[i] = s + 1;
        if(m < d[i])
            m = d[i];
    }
    return m;
}

int main(){
    int a[]={1,3,4,2,2,5,9,6,7};
    cout<<longDec(a,9)<<endl;
    return 0;
}
