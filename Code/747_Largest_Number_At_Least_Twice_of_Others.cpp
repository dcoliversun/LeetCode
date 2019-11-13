class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > nums[index]) {
                index = i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (index != i && nums[index] < 2 * nums[i]) {
                return -1;
            }
        }
        return index;
    }
};
