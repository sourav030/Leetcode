class Solution {
public:
    bool isPossible(vector<int>& nums, int target, int k){
        int count =1;
        int sum=0;
        for(int i=0; i<nums.size(); i++){

            if(nums[i]>target){
                return false;
            }
            if(sum+nums[i]<=target){
            sum+=nums[i];
            
            }
            else{
                count++;
                sum=nums[i];
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=0;
        int high=0;
        for(int i=0; i<nums.size(); i++){
            high+=nums[i];
            low=max(low,nums[i]);
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,mid,k)){
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