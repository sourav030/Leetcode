class Solution {
public:
    string reorganizeString(string s) {
        string ans="";
        unordered_map<char,int>mp;
        for(auto ele:s){
            mp[ele]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto ele:mp){
            pq.push({ele.second,ele.first});
        }
        while(!pq.empty()){
            int currCount=pq.top().first;
            char currChar=pq.top().second;
            pq.pop();
            int n=ans.length();
            if(n>=1 and ans[n-1]==currChar){
                if(pq.empty()){
                    return "";
                }
                int nextCount=pq.top().first;
                int nextChar=pq.top().second;
                pq.pop();
                ans+=nextChar;
                nextCount--;
                if(nextCount>0){
                    pq.push({nextCount,nextChar});
                }
                pq.push({currCount,currChar});
            }
            else{
                ans+=currChar;
                currCount--;
                if(currCount>0){
                    pq.push({currCount,currChar});
                }
            }

        }
        return ans;
    }
};