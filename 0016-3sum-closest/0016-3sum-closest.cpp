class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=0;
        int closed=INT_MAX;
        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size(); i++){
            int start=i+1;
            int end=nums.size()-1;

            while(start<end){
                int sum=nums[i]+nums[start]+nums[end];
                if(sum<target){
                    int a=abs(target-sum);
                    if(a<closed){
                        closed=a;
                        ans=sum;
                    }
                    start++;
                }
                else if(sum>target){
                     int a=abs(target-sum);
                    if(a<closed){
                        closed=a;
                        ans=sum;
                    }
                    end--;
                }
                else{
                    ans=sum;
                    return ans;
                }
            }

        }
        return ans;
    }
};