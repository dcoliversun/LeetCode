class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long lo = *max_element(nums.begin(), nums.end());
        long hi = 0;
        for (const int& num : nums) {
            hi += num;
        }
        while (lo < hi) {
            long mi = lo + (hi - lo) / 2;
            long tmp = 0;
            int cnt = 1;
            for (const int& num : nums) {
                tmp += num;
                if (tmp > mi) {
                    tmp = num;
                    ++cnt;
                }
            }
            if (cnt > m) lo = mi + 1;
            else hi = mi;
        }
        return lo;
    }
};
