#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

unsigned int elfHash(char *str)
{
    unsigned int h = 0, g;
    while(*str){
        h = (h << 4) + *(str++);//h左移4位，当前字符ASCII存入h的低四位
        if((g = h & 0xf0000000)!=0)//如果最高4位不为0，则说明字符多余7个，如果不处理，再加第九个字符时，第一个字符会被移出
            h ^= (g >> 24);//将28-32位与4-8位&
        h &= ~g;
    }
    return h;
}

int main()
{
    char str[1000];
    while(cin>>str) {
        cout<<elfHash(str)<<endl;
    }
    return 0;
}
