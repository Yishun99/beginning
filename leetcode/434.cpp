#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int sum=0;
        int i;
        for(i=0;i<s.length();i++){
            if(s[i]!=' '){
                sum++;
                while(s[i]!=' ' && i<s.length()) i++;
            }
        }
        return sum;
    }
};

int main()
{
    Solution my;
    string s = "Hello, my name is John";
    cout<<my.countSegments(s);
}
