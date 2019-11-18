class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> cnt(10000, 0);
        for (int& num : deck) {
            cnt[num]++;
        }
        int res = -1;
        for (int i = 0; i < 10000; ++i) {
            if (cnt[i] > 0) {
                if (res == -1) {
                    res = cnt[i];
                } else {
                    res = gcd(res, cnt[i]);
                }
            }
        }
        return res >= 2;
    }
    int gcd(int x, int y) {
        return x == 0 ? y : gcd(y % x, x);
    }
};
