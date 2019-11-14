class Solution {
public:
    bool isSub(string S, string str) {
        int i = 0, j = 0;
        while (i < S.size() && j < str.size()) {
            if (S[i] == str[j]) {
                ++j;
            }
            ++i;
        }
        return j == str.size();
    }
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<string, int> m;
        for (string& word : words) {
            m[word]++;
        }
        int res = 0;
        for (auto tmp : m) {
            if (isSub(S, tmp.first)) res += tmp.second;
        }
        return res;
    }
};
