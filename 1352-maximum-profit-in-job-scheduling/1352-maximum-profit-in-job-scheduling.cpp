class Solution {
public:
    int n;
    int find(vector<vector<int>>&array,int index,int nexJob){
        int start= index;
        int end=n-1;
        int result=n+1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(array[mid][0]>=nexJob){
                result=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
            return result;
    }
    int solve(vector<vector<int>>&array,int i,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int next=find(array,i+1,array[i][1]);
        int include=array[i][2]+solve(array,next,dp);
        int exclude=solve(array,i+1,dp);
        return dp[i]= max(include,exclude);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
         n=startTime.size();
        vector<vector<int>>array(n,vector<int>(3,0));
        for(int i=0; i<n; i++){
            array[i][0]=startTime[i];
            array[i][1]=endTime[i];
            array[i][2]=profit[i];
        }
        vector<int>dp(n+1,-1);
        sort(array.begin(),array.end());
        return solve(array,0,dp);
    }
};