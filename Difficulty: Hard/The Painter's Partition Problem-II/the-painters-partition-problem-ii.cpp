class Solution {
  public:
    bool solve(vector<int>&arr, int times,int k){
        int curr=1;
        int currTime=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>times){
                return false;
            }
            if(currTime+arr[i]>times){
                curr++;
                currTime=arr[i];
            }
            else{
                currTime+=arr[i];
            }
        }
        return curr<=k;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int low=0;
        int high=0;
        for(int i=0; i<arr.size(); i++){
            low=max(low,arr[i]);
            high+=arr[i];
        }
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(arr,mid,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};