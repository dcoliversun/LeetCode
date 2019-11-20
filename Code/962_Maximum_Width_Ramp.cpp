class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> stk;
        int res = 0;
        stk.push(0);
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] <= A[stk.top()]) {
                stk.push(i);
            }
        }
        for (int i = A.size() - 1; i >= 0; --i) {
            while (!stk.empty() && A[i] >= A[stk.top()]) {
                res = max(res, i - stk.top());
                stk.pop();
            }
        }
        return res;
    }
}; 
