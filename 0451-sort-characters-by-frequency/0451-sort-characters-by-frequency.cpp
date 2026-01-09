class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        for(auto ele:s){
            mp[ele]++;
        }
        string ans="";
        for(auto ele:mp){
            pq.push({ele.second,ele.first});
        }
        while(!pq.empty()){
            int count=pq.top().first;
            char ele=pq.top().second;
            ans+=string(count,ele);
            pq.pop();
        }
        return ans;
    }
};