class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,double>mp;
        for(auto ele:s){
            mp[ele]++;
        }
        priority_queue<pair<double,char>>pq;
        for(auto ele:mp){
            pq.push({ele.second,ele.first});
        }
        string ans="";
        while(!pq.empty()){
            int currChar=pq.top().second;
            double currCount=pq.top().first;
            pq.pop();
            if(ans.empty()){
                ans.push_back(currChar);
                currCount--;
                if(currCount>0)
                pq.push({currCount,currChar});
            }
            else{
                if(ans.back()!=currChar){
                    ans.push_back(currChar);
                    currCount--;
                }
                else{
                    if(pq.empty()){
                        return "";
                    }
                    int newCur=pq.top().second;
                    double newCount=pq.top().first;
                    pq.pop();
                    ans+=newCur;
                    newCount--;
                    if(newCount>0){
                        pq.push({newCount,newCur});
                    }
                }
                if(currCount>0){
                      pq.push({currCount,currChar});
                }
            }
        }
        return ans;
    }
};