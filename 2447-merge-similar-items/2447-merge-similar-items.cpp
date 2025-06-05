class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int>mp;
        vector<vector<int>>arr;
        for(int i=0; i<items1.size(); i++){
            if(mp.find(items1[i][0])!=mp.end()){
                mp[items1[i][0]]+=items1[i][1];
            }
            else{
                 mp[items1[i][0]]=items1[i][1];
            }
        }

        for(int i=0; i<items2.size(); i++){
            if(mp.find(items2[i][0])!=mp.end()){
                mp[items2[i][0]]+=items2[i][1];
            }
            else{
                 mp[items2[i][0]]=items2[i][1];
            }
        }
        for(auto [ele1,ele2]:mp){
            vector<int>ans(2,0);
            ans[0]=ele1;
            ans[1]=ele2;
            arr.push_back(ans);
        }
        
        return arr;
    }
};