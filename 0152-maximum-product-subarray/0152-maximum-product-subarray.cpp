class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product=INT_MIN;
        int prefix=1;
        int sufix=1;
        int n=nums.size();
        for(int i=0; i<nums.size(); i++){
            if(prefix==0) prefix=1;
            if(sufix==0) sufix=1;
            prefix=prefix*nums[i];
            sufix=sufix*nums[n-i-1];
            product=max(product,max(prefix,sufix));
        }
        return product;
    }
};