class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        for (int& num : arr) {
            if (stk.empty() || num >= stk.top()) {
                stk.push(num);
            } else {
                int top = stk.top();
                stk.pop();
                while (!stk.empty() && num < stk.top()) {
                    stk.pop();
                }
                stk.push(top);
            }
        }
        return stk.size();
    }
};
