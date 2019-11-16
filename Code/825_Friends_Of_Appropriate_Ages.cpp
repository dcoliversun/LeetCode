class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(121, 0);
        for (int& age : ages) {
            ++cnt[age];
        }
        int res = 0;
        for (int i = 1; i < 121; ++i) {
            if (cnt[i]) {
                int age_min = int(0.5 * i) + 8;
                int age_max = i;
                for (int j = age_min; j <= age_max; ++j) {
                    if (cnt[j]) {
                        if (i == j) {
                            res += cnt[i] * (cnt[i] - 1);
                        } else {
                            res += cnt[i] * cnt[j];
                        }
                    }
                }
            }
        }
        return res;
    }
};
