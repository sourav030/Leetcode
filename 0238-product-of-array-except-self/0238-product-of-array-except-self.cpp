class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long int product=1;
        int countZero=0;
        int indx=-1;
        int n=nums.size();
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                countZero++;
                indx=i;
            }
            else{
                product*=nums[i];
            }
        }
        if(countZero>1){
            vector<int>ans(n,0);
            return ans;
        }
        else if(countZero==1){
            vector<int>ans(n,0);
            ans[indx]=product;
            return ans;
        }
        else{
            vector<int>ans(n,0);
            for(int i=0; i<nums.size(); i++){
                ans[i]=product/nums[i];
            }
            return ans;
        }
    }
};