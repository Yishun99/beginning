#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        int nx, ny;
        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == 'R') { nx = x + 1; ny = y; }
            if (moves[i] == 'L') { nx = x - 1; ny = y; }
            if (moves[i] == 'U') { nx = x; ny = y + 1; }
            if (moves[i] == 'D') { nx = x; ny = y - 1; }
            x = nx; y = ny;
        }
        if (nx == 0 && ny == 0) return true;
        return false;
    }
};


int main() {
    Solution s;
    string str = "LR";
    cout<<s.judgeCircle(str);
    return 0;
}
