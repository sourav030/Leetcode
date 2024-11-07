class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
            int start=0;
            int end=0;
            int total=INT_MAX;
            while(end<nums.size())
            {
                    sum+=nums[end];
                    while(sum>=target)
                    {
                            total=min(total,end-start+1);
                            sum-=nums[start];
                            start++;
                    }
                    end++;
            }
            if(total==INT_MAX)
            {
                    return 0;
            }
            return total;
    }
};