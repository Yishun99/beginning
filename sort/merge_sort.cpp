#include <stdio.h>
void merge(int *arr, int l, int mid, int r) {
	int m = l, n = mid + 1, i=0;
	int *s = new int[r - l + 2];
	if(!arr) return;
	while (m <= mid && n <= r)
		s[i++] = (arr[m] < arr[n]) ? arr[m++] : arr[n++];
	while (m <= mid)
		s[i++] = arr[m++];
	while (n <= r)
		s[i++] = arr[n++];
	for(m = l, i = 0; m <= r; m++, i++)
		arr[m] = s[i];
}
void my_merge_sort(int arr[], int l, int r) {
	int mid;
    if (l < r) {
        mid = (l + r) / 2;
        my_merge_sort(arr, l, mid);
        my_merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void merge_sort(int arr[], int n) {
    int l = 0, r = n - 1;
    my_merge_sort(arr, l, r);
    return;
}

int main(void)
{
	int a[7]={2,1,9,3,7,5,8};
	int i;
	int left=0,right=6;
	merge_sort(a, 7);
	for(i=0;i<=right;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
