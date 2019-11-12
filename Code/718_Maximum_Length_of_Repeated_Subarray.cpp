class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int col = A.size(), row = B.size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (int i = 0; i < col; ++i) {
            if (B[0] == A[i]) dp[0][i] = 1;
        }
        for (int i = 0; i < row; ++i) {
            if (A[0] == B[i]) dp[i][0] = 1;
        }
        int res = 0;
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (B[i] == A[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};
