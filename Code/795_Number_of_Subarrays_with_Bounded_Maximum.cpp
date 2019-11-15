class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        A.push_back(R + 1);
        int edge = 0, left = 0;
        int all = 0, bad = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > R) {
                int d1 = i - edge;
                all += d1 * (d1 + 1) / 2;
                edge = i + 1;
                int d2 = i - left;
                bad += d2 * (d2 + 1) / 2;
                left = i + 1;
            } else if (A[i] >= L) {
                int d = i - left;
                bad += d * (d + 1) / 2;
                left = i + 1;
            }
        }
        return all - bad;
    }
};
