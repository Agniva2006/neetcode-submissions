class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int mxP = 0;
        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                 mxP = max(mxP, profit);
            } else {
                l = r;
            }
            r++;
        }
        return mxP;
    }
};
