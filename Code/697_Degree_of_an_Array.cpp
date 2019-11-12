class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> cnt(50000, 0);
        vector<int> start(50000), end(50000);
        int max_idx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            cnt[num] += 1;
            if (cnt[num] == 1) {
            start[num] = i;
            }
            end[num] = i;
            if (max_idx == -1) {
                max_idx = i;
            } else {
                int max_num = nums[max_idx];
                if (cnt[max_num] < cnt[num] || (cnt[max_num] == cnt[num] && end[max_num] - start[max_num] > end[num] - start[num])) {
                    max_idx = i;
                }
            }
        }
        if (max_idx == -1) return 0;
        int max_num = nums[max_idx];
        return end[max_num] - start[max_num] + 1;
    }
};
