#include<iostream>
#include<algorithm>
using namespace std;
int b[4] = {2,1,3,7};
int a[4] = {0,1,2,3};
int cmp(const int i, const int j) { return b[i] < b[j]; }

int main()
{
    sort(a, a+4, cmp);
    for(int i=0; i<4; i++)
        cout<<a[i]<<endl;
    return 0;
}
