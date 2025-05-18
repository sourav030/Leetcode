class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n,-1);
        if(n<2*k+1) return ans;
        vector<long long>prefix(n);
        prefix[0]=nums[0];
        for(int i=1; i<nums.size(); i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=k; i<nums.size()-k; i++){
            long long totalSum=prefix[i+k];
            long long sum=0;
            if(i-k>0){
                sum=prefix[i-k-1];
            }
            totalSum-=sum;
            int val=totalSum/(2*k+1);
            ans[i]=val;
        }
        return ans;
    }
};