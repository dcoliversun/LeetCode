class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum = accumulate(B.begin(), B.end(), 0) - accumulate(A.begin(), A.end(), 0);
        int delta = sum / 2;
        set<int> st(B.begin(), B.end());
        for (int& num : A) {
            if (st.count(num + delta)) {
                return {num, num + delta};
            }
        }
        return vector<int>();
    }
};
