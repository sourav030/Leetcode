class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int sum=0;
        int absDiff=INT_MAX;
        int start=0; 
        int end=nums.size()-1;
        for(int i=0; i<nums.size(); i++){
            int start=i+1;
            int end=nums.size()-1;
            while(start<end){
                long long sum=nums[i]+nums[start]+nums[end];
                if(absDiff>abs(target-sum)){
                    ans=sum;
                    absDiff=abs(target-sum);
                }

                if(sum==target){
                    return sum;
                }
                else if(sum>target){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return ans;
    }
};