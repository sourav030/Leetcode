class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs,int index, vector<int>&dp){
        if(index>=days.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int option1=costs[0]+solve(days,costs,index+1,dp);

        int i;
        for(i=index; i<days.size() and days[i]<days[index]+7;i++);
        int option2=costs[1]+solve(days,costs,i,dp);

        int j;
        for(j=index; j<days.size() and days[j]<days[index]+30; j++);
        int option3=costs[2]+solve(days,costs,j,dp);
        return dp[index]= min(option1 ,min(option2,option3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        return solve(days,costs,0,dp);
    }
};