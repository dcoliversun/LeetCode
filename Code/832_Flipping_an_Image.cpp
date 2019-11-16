class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return A;
        int col = A[0].size();
        for (vector<int>& row : A) {
            for (int i = 0; i < (col + 1) / 2; ++i) {
                int tmp = row[i] ^ 1;
                row[i] = row[col - 1 - i] ^ i;
                row[col - 1 - i] = tmp;
            }
        }
        return A;
    } 
};
