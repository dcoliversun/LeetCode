class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int len = nums.size();
        int left = 0, res = 0, mul = 1;
        for (int i = 0; i < len; ++i) {
            mul *= (long) nums[i];
            while (left <= i && mul >= k) {
                mul /= (long) nums[left];
                ++left;
            }
            res += i - left + 1;
        }
        return res;
    }
};
