class Solution {
     int find(int index,int amount,vector<int>& coins,vector<vector<int>> &dp){
        if(amount==0){
            return 1;
        }
        if(index<0){
            return 0;
        }

        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        if(coins[index]>amount){
            return dp[index][amount]=find(index-1,amount,coins,dp);
        }
        // ab hum first coin ko use krenege
        // phir first ko use nhi krenge
        return dp[index][amount]=find(index,amount-coins[index],coins,dp)+find(index-1,amount,coins,dp);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size()-1;
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return find(n,amount,coins,dp);
    }
};