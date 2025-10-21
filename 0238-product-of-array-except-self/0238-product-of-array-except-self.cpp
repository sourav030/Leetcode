class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int countZero=0;
        int multiply=1;
        int index=-1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                countZero++;
                index=i;
            }
            else{
                multiply=multiply*nums[i];
            }
        }
        if(countZero>1){
            return ans;
        }
        if(countZero==1){
            ans[index]=multiply;
            return ans;
        }

        for(int i=0; i<nums.size(); i++){
            ans[i]=multiply/nums[i];
        }
        return ans;
    }
};