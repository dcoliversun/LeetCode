class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int len = A.size();
        vector<vector<int>> count(2 * len + 1, vector<int>(2 * len + 1, 0));
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (A[i][j] == 1) {
                    for (int i2 = 0; i2 < len; ++i2) {
                        for (int j2 = 0; j2 < len; ++j2) {
                            if (B[i2][j2] == 1) {
                                ++count[i - i2 + len][j - j2 + len];
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (vector<int>& row : count) {
            for (int& col : row) {
                ans = max(ans, col);
            }
        }
        return ans;
    }
};
