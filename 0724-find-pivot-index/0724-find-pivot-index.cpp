class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>prefixSum;
        int sum=0;
        int ans=-1;
        for(auto ele:nums){
            sum+=ele;
            prefixSum.push_back(sum);
        }

        for(int i=0; i<prefixSum.size(); i++){
            if(i==0){
                if(prefixSum[i]==sum){
                    return i;
                }
                continue;
            }
            int target=sum-prefixSum[i];
            int val=prefixSum[i-1];
            if(target==val){
                ans=i;
                return ans;
            }
        }

        return ans;
    }
};