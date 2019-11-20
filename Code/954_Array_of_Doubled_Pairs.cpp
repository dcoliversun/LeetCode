class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int, int> cnt;
        for (const int& num : A) {
            ++cnt[abs(num)];
        }
        cnt.erase(0);
        while (!cnt.empty()) {
            const int maxnum = cnt.rbegin()->first;
            const int half = maxnum / 2;
            if (maxnum & 1) return false;
            else if (cnt[half] < cnt[maxnum]) return false;
            cnt[half] -= cnt[maxnum];
            cnt.erase(maxnum);
            if (cnt[half] == 0) cnt.erase(half);
        }
        return true;
    }
};
