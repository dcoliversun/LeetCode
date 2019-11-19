class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.size() < 2) return 0;
        sort(A.begin(), A.end());
        int cur = A[0], res = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] <= cur) {
                res += cur - A[i] + 1;
                ++cur;
            } else {
                cur = A[i];
            }
        }
        return res;
    }
};                
