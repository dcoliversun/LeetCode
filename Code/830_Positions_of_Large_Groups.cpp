class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        if (S.empty()) return res;
        int i = 0;
        for (int j = 0; j < S.size(); ++j) {
            if (j == S.size() - 1 || S[j] != S[j + 1]) {
                if (j - i  + 1>= 3) {
                    res.push_back({i, j});
                }
                i = j + 1;
            }
        }
        return res;
    }
};
