class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int start=0;
        int end=n-1;
        while(start<=end){
            int a=nums[start];
            int b=nums[end];
            if(abs(a)>abs(b)){
                if(n>0){
                    n--;
                    ans[n]=pow(a,2);
                }
                start++;
            }
            else{
                 if(n>0){
                    n--;
                    ans[n]=pow(b,2);
                }
                end--;
            }
        }
        return ans;
    }
};