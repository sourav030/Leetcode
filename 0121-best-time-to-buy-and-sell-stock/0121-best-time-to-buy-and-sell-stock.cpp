class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int miniPrice=prices[0];
        int ans=0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]<miniPrice){
                miniPrice=prices[i];
            }
            ans=max(ans,prices[i]-miniPrice);
        }
        return ans;
    }
};