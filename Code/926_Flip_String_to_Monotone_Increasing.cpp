class Solution {
public:
    int minFilpMonoIncr(string S) {
        const int len = S.size();
        vector<int> prefixSum(len + 1, 0);
        for (int i = 0; i < len; ++i) {
            prefixSum[i + 1] = prefixSum[i] + (S[i] == '1' ? 1 : 0);
        }
        int res = INT_MAX;
        for (int i = 0; i <= len; ++i) {
            res = min(res, 2 * prefixSum[i] + len - i - prefixSum[len]);
        }
        return res;
    }
};
