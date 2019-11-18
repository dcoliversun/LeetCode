class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        const int mod = 1e9 + 7;
        const int len = A.size();
        vector<long long> pow2(len, 1);
        for (int i = 1; i < len; ++i) {
            pow2[i] = pow2[i - 1] * 2 % mod;
        }
        sort(A.begin(), A.end());
        long long ans = 0;
        for (int i = 0; i < len; ++i) {
            ans += (1ll * A[i]) % mod * ((pow2[i] - pow2[len - 1 - i] + mod) % mod) % mod;
            if (ans >= mod) ans -= mod;
        }
        return (int) ans;
    }
};
