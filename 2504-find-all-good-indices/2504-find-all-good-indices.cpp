class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>decre(n,1);
        vector<int>incre(n,1);
        for(int i=1; i<n; i++){
            if(nums[i]<=nums[i-1]){
                decre[i]=decre[i-1]+1;
            }
            else{
                decre[i]=1;
            }
        }

        for(int j=n-2; j>=0; j--){
            if(nums[j]<=nums[j+1]){
                incre[j]=incre[j+1]+1;
            }
            else{
                incre[j]=1;
            }
        }

        vector<int> ans;

        for(int i = k; i < n - k; i++) {
            if (incre[i + 1] >= k && decre[i - 1] >= k) {
                ans.push_back(i);
            }
        }

        return ans;

    }
};