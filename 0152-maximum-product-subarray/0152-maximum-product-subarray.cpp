class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefixMul=1;
        int sufixMul=1;
        int n=nums.size()-1;
        int ans=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            prefixMul=prefixMul*nums[i];
            sufixMul=sufixMul*nums[n-i];
            ans=max({prefixMul,sufixMul,ans});
            if(prefixMul==0) prefixMul=1;
            if(sufixMul==0) sufixMul=1;
        }
        return ans;
    }

};