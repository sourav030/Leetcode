class Solution {
  public:
    bool solve(vector<int>&stalls, int k, int dis){
        int count=1;
        int prev=stalls[0];
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i]>=prev+dis){
                count++;
                prev=stalls[i];
            }
        }
        return count>=k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high = stalls[n-1] - stalls[0];
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(stalls, k, mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
        
    }
};