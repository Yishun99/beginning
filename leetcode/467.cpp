#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> a(26, 0);
        int maxlen=0;
        for(int i=0;i<p.length();i++){
            int cur = p[i]-'a';
            if(i>0&&(p[i]-p[i-1]==1||p[i-1]-p[i]==25))maxlen++;
            else maxlen=1;
            a[cur]=max(a[cur],maxlen);
        }
        int sum=0;
        for(int i=0;i<26;i++)sum+=a[i];
        return sum;
    }
};

int main()
{
    Solution my;
    string s="abcdcde";
    cout<<my.findSubstringInWraproundString(s);
    return 0;
}
