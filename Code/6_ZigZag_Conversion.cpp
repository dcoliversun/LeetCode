class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        const int len = s.size();
        int cycLen = 2 * numRows - 2;
        string res;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j + i < len; j += cycLen) {
                res += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycLen - i < len) {
                    ret += s[j + cycLen - i];
                }
            }
        } 
        return res;
    }
};
