#include<iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
    	int cnt=0;
    	int i=10;
    	while(float(n/i)>=1)
    	{
    		cnt=cnt+n/i;
    		i=i*10;
    	}
    	int j=5;
    	while(j<=n)
    	{
    		j=j+10;
    		cnt;

    	}
    	return cnt;
        
    }
};



class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5) return 0;
        int cnt=0;
        while(n){
        	cnt+=n/5;
        	n/=5;
        }
        return cnt;
    }
};




n/5+n/(5*5)+n/(5*5*5)+...



int main()
{
	Solution s;
	int n;
	while(cin>>n){
		cout<<s.trailingZeroes(n)<<endl;
	}
}