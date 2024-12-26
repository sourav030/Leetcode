class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount=0;
        int product=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                zeroCount++;
            }
            else{
                product*=nums[i];
            }
        }
        int n=nums.size();
        vector<int>ans(n,0);
        if(zeroCount>1){
           
            return ans;
        }
        else if (zeroCount==1){

            for(int i=0; i<n; i++){
                if(nums[i]!=0)
                {
                ans[i]=0;
                }
                else{
                ans[i]=product;
                }
            }   
        }
        else {
            for(int i=0; i<n; i++){
                ans[i]=product/nums[i];
            }
        }
        return ans;
    }
};