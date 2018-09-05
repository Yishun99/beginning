#include<iostream>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#include<stack>

using namespace std;

struct Log{
    int id;
    string status;
    int time_stamp;
    Log(int i, string s, int t) : id(i), status(s), time_stamp(t) {};
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> time(n, 0);
        stack<Log> st;
        for (string log : logs) {
            stringstream ss(log);
            string tmp1, tmp2, tmp3;
            getline(ss, tmp1, ':');
            getline(ss, tmp2, ':');
            getline(ss, tmp3, ':');
            Log item(stoi(tmp1), tmp2, stoi(tmp3));
            if (item.status == "start") {
                st.push(item);
            } else {
                assert(st.top().id == item.id);
                int time_added =  item.time_stamp - st.top().time_stamp + 1;
                time[item.id] += time_added;
                st.pop();
                if (!st.empty()) {
                    assert(st.top().status == "start");
                    time[st.top().id] -= time_added;
                }
            }
        }
        return time;
    }
};






