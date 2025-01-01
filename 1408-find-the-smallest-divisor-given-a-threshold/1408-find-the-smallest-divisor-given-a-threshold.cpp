class Solution {
public:
    int solve(vector<int>&nums, int divide){
        int ans=0;
        for(int i=0; i<nums.size(); i++){
           ans += ceil((double)nums[i] / divide);

        }
        return ans;;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        
        if(nums.size()>threshold){
            return -1;
        }
        int low=1;
        int heigh=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            heigh=max(heigh,nums[i]);
        }
        int s=-1;
        while(low<=heigh){
            int mid=low+(heigh-low)/2;
            int ans=solve(nums,mid);
            if(ans<=threshold){
                heigh=mid-1;
                s=mid;
            }
            else{
                low=mid+1;
            }
        }
        return s;
    }
};