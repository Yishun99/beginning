#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<vector<int>> w;
stack<int> result;

void play(vector<int> &order) {
    int len = order.size(), i;
    if (len == 1) {
        result.push(order[0]);
        return;
    }
    vector<int> nx_order;
    for (i = 0; i < len - 1; i += 2) {
        int tmp = w[i][i+1];
        nx_order.push_back(tmp);
        result.push(i == tmp ? i + 1 : i);
    }
    if (i < len) nx_order.push_back(order[len - 1]); //处理order中为奇数的情况
    play(nx_order);
}

vector<int> my_fun(vector<int> &order) { //函数入口
    while (!result.empty()) result.pop();
    play(order);
    vector<int> ret;
    while (!result.empty()) { ret.push_back(result.top()); result.pop(); }
    return ret;
}

int main() {
    //init w
    //init order
    my_fun(order);
}
