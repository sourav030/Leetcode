class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto ele:nums){
            mp[ele]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto ele:mp){
            pq.push({ele.second,ele.first});
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};