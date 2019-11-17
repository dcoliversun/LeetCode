class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        multiset<int> MS(A.begin(), A.end());
        typedef multiset<int>::iterator mit;
        for (int i = 0; i < N; ++i) {
            mit it = MS.upper_bound(B[i]);
            if (it == MS.end()) {
                A[i] = *MS.begin();
                MS.erase(MS.begin());
            } else {
                A[i] = *it;
                MS.erase(it);
            }
        }
        return A;
    }
};
