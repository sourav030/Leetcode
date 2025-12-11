class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int mult=1;
        int zero=0;
        int index=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                mult=mult*nums[i];
            }
            else{
                zero++;
                index=i;
            }
            if(zero>1){
                return ans;
            }
        }

        if(zero==1){
            ans[index]=mult;
        }
        else{
            for(int i=0; i<nums.size(); i++){
                ans[i]=mult/nums[i];
            }
        }
        return ans;

    }
};