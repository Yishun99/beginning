class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length(), dp = 1, m = 1, i, j;
        if (!len) return 0;
        hash_set<char> st;
        st.insert(s[0]);
        for (i = 1; i < len; i++) {
            if (st.find(s[i]) == st.end()) dp += 1;
            else {
                st.clear();
                j = i - 1;
                while (s[j] != s[i]) {
                    st.insert(s[j]);
                    j--;
                }
                dp = i - j;
            }
            st.insert(s[i]);
            if (dp > m) m = dp;
        }
        return m;
    }
};
