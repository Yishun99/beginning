#include<iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int cnt=0;
        int i=1;
        while(n>=i)
        {
        	n=n-i;
        	i++;
        	cnt++;
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    cout<<s.arrangeCoins(10)<<endl;
    return 0;
}
