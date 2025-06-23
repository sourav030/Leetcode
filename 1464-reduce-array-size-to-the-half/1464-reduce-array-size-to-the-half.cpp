class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto ele:mp){
            pq.push({ele.second,ele.first});
        }
        int ans=0;
        int count=0;
        while(!pq.empty()){
            count+=pq.top().first;
            pq.pop();
            ans++;
            if(count>=n/2){
                return ans;
            }
        }
        return ans;
    }
};