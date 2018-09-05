class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int m = INT_MAX, ix = 0, len = arr.size();
        for (int i = 0; i < len; i++)
            if (abs(arr[i] - x) < m) {
                m = abs(arr[i] - x);
                ix = i;
            }
        vector<int> ret;
        int l = ix - 1, r = ix + 1;
        while(--k) {
            if (l >= 0 && r < len) {
                if (abs(arr[l] - x) <= abs(arr[r] - x)) l--;
                else r++;
            }
            else if (l >= 0) l--;
            else if (r < len) r++;
        }
        for (int i = l + 1; i < r; i++) ret.push_back(arr[i]);
        return ret;
    }
};
