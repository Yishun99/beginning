#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int cnt1,cnt2,i,j;
        cnt1=cnt2=i=j=0;
        int len1=s1.length(),len2=s2.length();
        while(cnt1<n1){
            if(s1[i]==s2[j])j++;
            i++;
            if(i==len1){cnt1++;i=0;}
            if(j==len2){cnt2++;j=0;}
        }
        return cnt2/n2;
    }
};

int main()
{
    Solution my;
    cout<<my.getMaxRepetitions("acb", 4, "ab", 2);
    return 0;
}
