class Solution {
public:
    int subarraySum(vector<int>& nums, int K) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
           

            int dif=sum-K;

            if(mp.find(dif)!=mp.end()){
                ans+=mp[dif];
                mp[sum]++;
            }
            else{
                mp[sum]++;
            }

        }
        return ans;
    }
};