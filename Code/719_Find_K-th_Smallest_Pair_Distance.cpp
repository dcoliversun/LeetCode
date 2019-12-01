class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = *nums.rbegin() - *nums.begin();
        while (lo < hi) {
            int count = 0, left = 0;
            int mi = lo + (hi - lo) / 2;
            for (int right = 0; right < nums.size(); ++right) {
                while (nums[right] - nums[left] > mi) ++left;
                count += right - left;
            }
            if (count >= k) hi = mi;
            else lo = mi + 1;
        }
        return lo;
    }
};
