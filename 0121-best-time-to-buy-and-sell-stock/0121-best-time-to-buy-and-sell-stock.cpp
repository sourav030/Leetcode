class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=INT_MIN;
        int minPrice=prices[0];
        for(int i=0; i<prices.size(); i++){
            minPrice=min(minPrice,prices[i]);
            profit=max(profit,prices[i]-minPrice);
        }
        return profit;
    }
};