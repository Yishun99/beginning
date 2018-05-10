#include<iostream>
#include<algorithm>
using namespace std;


void swap1(int *a, int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
void qsort(int *a, int l, int r)
{
    if(l >= r)
        return;
    int mid = (l + r) / 2;
    swap1(a, mid, l);
    int t = l;
    for(int i=l+1; i<=r; i++){
        if(a[i]<a[l]){
            swap1(a, i, ++t);//t记录pivot的真正位置，每有一个小于pivot的就加一
        }
    }
    swap1(a, l, t);
    qsort(a, l, t - 1);
    qsort(a, t + 1, r);
}

int main()
{
    int a [9] = {10,6,2,4,5,2,4,7,9};
    qsort(a, 0, 8);
    for(int i=0; i<9; i++)
        cout<<a[i]<<endl;

    return 0;
}


