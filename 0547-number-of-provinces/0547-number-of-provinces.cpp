class Solution {
public:

    unordered_map<int,vector<int>>mp;
    void dfs(vector<int>&visited, int idx){
        visited[idx]=1;
        for(auto ele:mp[idx]){
            if(!visited[ele]){
                dfs(visited,ele);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        // This is our graph
        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected[0].size(); j++){
                if(i!=j and isConnected[i][j]==1){
                    mp[i+1].push_back(j+1);
                }
            }
        }
        vector<int>visited(n+1,0);
        int count=0;
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                count++;
                dfs(visited,i);
            }
        }
        return count;

    }
};