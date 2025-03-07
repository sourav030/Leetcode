class Solution {
public:
    int solve(vector<int>& job, int index, int n,int d, vector<vector<int>> &dp){
            if(d==1){
                return *max_element(job.begin()+index,job.end());
            }
            if(dp[index][d]!=-1){
                return dp[index][d];
            }
            int maxi=0; int mini=INT_MAX;
            for(int i=index; i<n-d+1;i++){
                maxi=max(maxi,job[i]);
                mini=min(mini,maxi+solve(job,i+1,n,d-1,dp));
            }
            return dp[index][d]= mini;
    }
    int minDifficulty(vector<int>& job, int d) {
            if(d>job.size()){
                return -1;
            }
            int n=job.size();
            vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
           return solve(job,0,n,d,dp);
    }
};