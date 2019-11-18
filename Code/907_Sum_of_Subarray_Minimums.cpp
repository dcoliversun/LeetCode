class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        typedef pair<int, int> pr;
        const int mod = 1e9 + 7;
        stack<pr> stk;
        int ans = 0, dot = 0;
        for (int j = 0; j < A.size(); ++j) {
            int count = 1;
            while (!stk.empty() && stk.top().first >= A[j]) {
                pr node = stk.top();
                stk.pop();
                count += node.second;
                dot -= node.first * node.second;
            }
            stk.push({A[j], count});
            dot += A[j] * count;
            ans += dot;
            ans %= mod;
        }
        return ans;
    }
};
