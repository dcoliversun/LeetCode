class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int j = -1, i = 0, res = 0;
        for (;i < seats.size(); ++i) {
            if (seats[i] == 1) {
                res = (j == -1) ? max(res, i) : max(res, (i - j) / 2);
                j = i;
            }
        }
        res = max(res, i - j - 1);
        return res;
    }
};
