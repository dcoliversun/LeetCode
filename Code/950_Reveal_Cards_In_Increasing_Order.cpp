class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        const int len = deck.size();
        vector<int> res(len, 0);
        int i = 0, j = 1;
        while (j < len) {
            int empty = 0;
            while (empty < 2) {
                i = (i + 1) % len;
                if (res[i] == 0) ++empty;
            }
            res[i] = deck[j++];
        }
        return res;
    }
};
