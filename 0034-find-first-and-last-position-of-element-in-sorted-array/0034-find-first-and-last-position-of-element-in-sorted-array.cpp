class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
            
            // first occurance hamesa left side hoga to element ke mileane ke bad fir se left side check krenge
// last occurance hamesa right side hoga to element milane ke bad bhi hum right side dkhenge
        int first=-1;
            int second=-1;
            int f=0;
            int end=nums.size()-1;
            while(f<=end){
                    int mid=f+(end-f)/2;
                    if(nums[mid]> target)
                    {
                            end=mid-1;
                    }
                    else if(nums[mid]< target)
                    {
                            f=mid+1;
                    }
                    else{
                            first=mid;
                            end=mid-1;
                    }
            }
            
            f=0;
            end=nums.size()-1;
                 while(f<=end){
                    int mid=f+(end-f)/2;
                    if(nums[mid]> target)
                    {
                            end=mid-1;
                    }
                    else if(nums[mid]< target)
                    {
                            f=mid+1;
                    }
                    else{
                            second=mid;
                            f=mid+1;
                    }
            }
            return {first,second};
    }
};