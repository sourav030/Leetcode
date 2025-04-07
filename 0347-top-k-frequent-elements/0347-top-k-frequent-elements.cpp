class Solution {
public:
    static bool comp(pair<int,int>a, pair<int,int>b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(auto ele:nums){
            mp[ele]++;
        }
        vector<pair<int,int>>arr(mp.begin(),mp.end());

        sort(arr.begin(),arr.end(), comp);
        vector<int>ans;
        int i=0;

        while(k--){
            ans.push_back(arr[i].first);
            i++;
        }
        return ans;
    }
};