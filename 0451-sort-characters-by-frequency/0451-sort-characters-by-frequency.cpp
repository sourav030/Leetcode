class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        string ans="";
        priority_queue<pair<int,char>>pq;
        for(auto ele:mp){
            pq.push({ele.second,ele.first});
        }
        while(!pq.empty()){
            int count=pq.top().first;
            char ch=pq.top().second;
            ans+=string(count,ch);
            pq.pop();
        }
        return ans;
    }
};