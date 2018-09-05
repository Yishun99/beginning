class Solution {
public:
    int numTrees(int n) {
        vector<int> a(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            int sum = 0;
            for (int j = 0; j < i; j++) sum += a[j] * a[i - 1 - j];
            a[i] = sum;
        }
        return a[n];
    }
};
