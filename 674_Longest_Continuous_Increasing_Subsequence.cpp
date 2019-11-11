class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int res = 1, count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                ++count;
            } else {
                count = 1;
            }
            res = max(res, count);
        }
        return res;
    }
};
