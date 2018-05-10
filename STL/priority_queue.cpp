#include <iostream>
#include <vector>
#include <cstring>
#include <functional>
#include <queue>

using namespace std;

const int maxn = 1000 + 10;

class myCmp
{
public:
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const{
        return a.first > b.first;
    }
};


class Solution {


public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int pos[100000];
        memset(pos, 0, sizeof(pos));
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCmp> pq; /////////////////////
        for(int i=0; i<n; i++) {
            pq.push( pair<int, int>(matrix[i][pos[i]], i)); ///////////////////////////
        }
        for(int i=0; i<k-1; i++){
            int row = pq.top().second;
            pq.pop();
            while(pos[row] >= n-1){
                row = pq.top().second;
                if(i==k-2)
                    return pq.top().first;
                pq.pop();
                i++;
            }
            pos[row]++;
            pq.push(pair<int, int>(matrix[row][pos[row]], row));
        }
        return pq.top().first;
    }
};


int main()
{
    vector<vector<int>> vec { { 1, 5, 9},
                              { 10, 11, 13},
                              {12, 13, 15} };

    Solution s;
    for(int i=1;i<=9;i++)
        cout<<s.kthSmallest(vec, i)<<endl;

    return 0;
}
