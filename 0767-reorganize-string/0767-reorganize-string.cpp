class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        for(auto ele:s){
            mp[ele]++;
        }
        for(auto ele:mp){
            pq.push({ele.second,ele.first});
        }
        string ans="";
        while(!pq.empty()){
            int count=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            ans+=ch;
            count--;
            if(!pq.empty()){
                int count2=pq.top().first;
                char ch2=pq.top().second;
                pq.pop();
                ans+=ch2;
                count2--;
                if(count2>0){
                    pq.push({count2,ch2});
                }
                if(count>0){
                    pq.push({count,ch});
                }
            }
            else if(count!=0 and pq.empty()){
                return "";
            }
        }
        return ans;
    }
};