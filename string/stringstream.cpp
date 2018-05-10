#include <sstream>
#include <iostream>
#include <cstring>
#include<vector>

using namespace std;

int main() {
    string str = "0:start:12";
    stringstream iss(str);

    string s;
    int a, b;
    iss >> a >> s >> b;
    cout << a << " " << " " << " " << b << " " << endl;
}
