class Solution {
public:
    string preProcess(string s) {
        if (s.empty()) return "^$";
        string ret = "^";
        for (int i = 0; i < s.size(); ++i) {
            ret += "#" + s.substr(i, 1);
        }
        ret += "$";
        return ret;
    }
    string longestPalindrome(string s) {
        string T = preProcess(s);
        int len = T.size();
        vector<int> p(len);
        int C = 0, R = 0;
        for (int i = 1; i < len - 1; ++i) {
            int i_mirror = 2 * C - i;
            p[i] = (R > i) ? min(R - i, p[i_mirror]) : 0;
            while (T[i + 1 + p[i]] == T[i - 1 - p[i]]) p[i]++;
            if (i + p[i] > R) {
                C = i;
                R = i + p[i];
            }
        }
        auto center = max_element(p.begin() + 1, p.end() - 1);
        int maxLen = *center;
        int centerIndex = center - p.begin();
        return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
    }
};
