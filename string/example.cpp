/*
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。 
处理:
1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
3.输入的文件可能带路径，记录文件名称不能带路径

输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

    文件路径为windows格式

    如：E:\V1R2\product\fpgadrive.c 1325

输出描述:
将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1 

    结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。

    如果超过8条记录，则只输出前8条记录.

    如果文件名的长度超过16个字符，则只输出后16个字符

输入例子1:
E:\V1R2\product\fpgadrive.c 1325

输出例子1:
fpgadrive.c 1325 1
*/

#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;

struct Node{
    string a, b;
    int c; 
}node[10];


bool cmp(Node x, Node y){
    return x.c>y.c;
}

int main() {
    string str, path, line;
    int cnt = 0;

    map<string, int> mp;
    vector<string> v;

    freopen("data", "r", stdin);
    while (cin>>path>>line) {
        int pos = 0;
        if ((pos = path.find_last_of("/\\")) != std::string::npos)
            path = path.substr(pos+1);
        str = path + "+" + line;
        if (mp[str] == 0) {
            mp[str]++;
            cnt++;
            v.push_back(str);
        } else {
            mp[str]++;
        }
    }
    for (int i = 0; i < cnt; i++) {
        str = v[i];
        int f = str.find('+');
        path = str.substr(0, f);
        line  = str.substr(f+1);
        int len = path.length();
        if (len > 16) {
            path = path.substr(len-16);
        }
        node[i].a = path, node[i].b = line, node[i].c = mp[str];
    }
    sort(node, node+cnt, cmp);
    for (int i = 0; i<min(cnt, 8); i++) {
        cout<<node[i].a<<" "<<node[i].b<<" "<<node[i].c<<endl;
    }
    return 0;
}

