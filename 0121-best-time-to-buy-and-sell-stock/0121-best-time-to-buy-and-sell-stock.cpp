class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sellProduct=prices[0];
        int maxProfit=-1;
        for(int i=1; i<prices.size(); i++){
            int profit=prices[i]-sellProduct;
            maxProfit=max(maxProfit,profit);
            if(prices[i]<sellProduct){
                sellProduct=prices[i];
            }
        }
        if(maxProfit<0){
            return 0;
        }
        return maxProfit;
    }
};