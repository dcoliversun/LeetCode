class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
	int len = prices.size();
	int dp_0 = 0, dp_1 = INT_MIN;
	for (int i = 0; i < len; ++i) {
	    int tmp = dp_0;
	    dp_0 = max(dp_0, dp_1 + prices[i]);
	    dp_1 = max(dp_1, tmp - prices[i] - fee);
	}
	return dp_0;
    }
};
