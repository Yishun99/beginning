#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int maxn = 1000 + 10;


class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> ret;
        queue<int> q;
        int n = ppid.size();
        ret.push_back(kill);
        for(int i=0; i<n; i++){
        	if(ppid[i] == kill){
        		q.push(pid[i]);
        		while(!q.empty()){
        			int now = q.front();
        			ret.push_back(now);
        			for(int j=0; j<n; j++){
        				if(ppid[j] == now)
        					q.push(pid[j]);
        			}
        			q.pop();
        		}
        	}
        }
        return ret;
    }
};


class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> ret;
        int n = ppid.size();
        ret.push_back(kill);
        for(int i=0; i<n; i++){
        	if(ppid[i] == kill)
        		vector<int> = killProcess(pid, ppid, pid[i]);
        }
    }
};




int main()
{
	
	return 0;
}