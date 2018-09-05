#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        vector<vector<int>> ret;
        vector<int> tmp;
        backtrack(a, t, 0, 0, ret, tmp);
        return ret;
    }
    void backtrack(vector<int>& a, int t, int cur, int ans, vector<vector<int>>& ret, vector<int>& tmp) {
        if (cur == a.size()) {
            if (ans == t) ret.push_back(tmp);
            return;
        }
        if (ans > t) return;
        int mul = 0;
        while (mul * a[cur] <= t) {
            for (int i = 0; i < mul; i++) tmp.push_back(a[cur]);
            backtrack(a, t, cur + 1, ans + mul * a[cur], ret, tmp);
            for (int i = 0; i < mul; i++) tmp.pop_back();
            mul++;
        }
    }
};


int main()
{
    Solution s;
    vector<int> a = {2,3,6,7};
    vector<vector<int>> v = s.combinationSum(a, 7);
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[0].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
