class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int miniprice=prices[0];
        for(int i=0; i<prices.size(); i++){
            miniprice=min(prices[i],miniprice);
            profit=max(profit,prices[i]-miniprice);
        }
        return profit;
    }
};