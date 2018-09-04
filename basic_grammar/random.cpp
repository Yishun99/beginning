#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 + 10;


//从0到n-1中随机等概率输出m个不同的数
//x = rand() % a + b
void random(int n, int m)
{
	for(int i=0; i<n; i++){
		if(rand() % (n-i) < m){
			cout<<i<<endl;
			m--;
		}
	}
}

int main()
{
	random(100, 30);
	return 0;
}
