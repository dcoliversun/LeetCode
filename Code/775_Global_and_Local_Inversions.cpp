class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int len = A.size();
        int floor = len;
        for (int i = len - 1; i >= 2; --i) {
            floor = min(floor, A[i]);
            if (A[i - 2] > floor) return false;
        }
        return true;
    }
};
