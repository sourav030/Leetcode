class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countZero=0;
        int index=-1;
        long long product=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                countZero++;
                index=i;
            }
            else{
                product=product*nums[i];
            }
        }

        if(countZero>1){
            int n=nums.size();
            vector<int>ans(n,0);
            return ans;
        }
        else if(countZero==1){
            int n=nums.size();
            vector<int>ans(n,0);
            ans[index]=product;
            return ans;
        }
        else{
            vector<int>ans;
            for(int i=0; i<nums.size(); i++){
                int val=product/nums[i];
                ans.push_back(val);
            }
            return ans;
        }
    }
};