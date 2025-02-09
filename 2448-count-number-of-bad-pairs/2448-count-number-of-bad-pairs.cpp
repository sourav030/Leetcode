class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        long long good=0;
        int n=nums.size();
        long long total = (long long)n * (n - 1) / 2;
        vector<int>ans;
        
        for(int i=0;i<n; i++){
            ans.push_back(i-nums[i]);
        }
        for(int i=0; i<ans.size(); i++){
            if(mp.find(ans[i])!=mp.end()){
                good+=mp[ans[i]];
            }
            mp[ans[i]]++;
        }
        return total-good;

    }
};