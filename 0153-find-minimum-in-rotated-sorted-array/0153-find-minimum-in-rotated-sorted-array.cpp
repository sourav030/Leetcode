class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=nums[0];
            int start=0;
            int end=nums.size()-1;
            while(start<=end)
            {
                    int mid=start+(end-start)/2;
                    if(nums[mid]>=nums[0])
                    {
                            start=mid+1;
                    }
                    else{
                            ans=nums[mid];
                            end=mid-1;
                    }
            }
            return ans;
    }
};