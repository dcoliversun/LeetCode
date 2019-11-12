class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, res = 0, len = 0;
        while (end < s.size()) {
            for (int i = start; i < end; ++i) {
                if (s[end] == s[i]) {
                    start = i + 1;
                    len = end - start;
                    break;
                }
            }
            ++end;
            ++len;
            res = max(res, len);
        }
        return res;
    }
};
