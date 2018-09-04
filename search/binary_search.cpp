#include<iostream>
using namespace std;

bool bisearch(int *a, int n, int k) {
    int l = 0, r = n - 1, mid;
    while (l < r) {
        int mid = (l + r) / 2;
        if (k > a[mid]) l = mid + 1; 
        else if (k < a[mid]) r = mid - 1;
        else return true;
    }
    return false;
}

bool bisearch2(int *a, int k, int l, int r) {
	int mid = (l + r) / 2;
	if (l > r)
		return false;
	if (a[mid] == k)
		return true;
	else if (k > a[mid])
		return bisearch2(a, k, mid + 1, r);
	else 
		return bisearch2(a, k, l, mid - 1);
}


int main()
{
    int a[] = {1,3,6,9};
    cout<<bisearch(a, 4, 7);
    return 0;
}
