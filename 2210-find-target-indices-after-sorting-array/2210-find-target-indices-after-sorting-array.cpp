class Solution {
public:
    int lowerBound(vector<int>&nums, int target){
        int low=0;
        int ans=-1;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int UpperBound(vector<int>&nums, int target){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); 
        int i=lowerBound(nums,target);
        int j=UpperBound(nums,target);
        
        vector<int>ans;
        if(i==-1 or j==-1) return ans;
        for(int k=i; k<=j; k++){
            ans.push_back(k);
        }
        return ans;
    }
};