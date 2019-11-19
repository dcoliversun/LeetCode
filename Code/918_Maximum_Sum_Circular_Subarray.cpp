class Solution {
public:
    int maxSubarraySum(vector<int>& A) {
        if (A.size() == 1) return A[0];
        int cur = A[0];
        int maxres = cur, sum = cur;
        for (int i = 1; i < A.size(); ++i) {
            sum += A[i];
            cur = (cur < 0) ? A[i] : cur + A[i];
            maxres = max(maxres, cur);
        }
        cur = 0;
        int minres = 0;
        for (int i = 1; i < A.size() - 1; ++i) {
            cur = (cur > 0) ? A[i] : cur + A[i];
            minres = min(minres, cur);
        }
        return max(maxres, sum - minres);
    }
};
