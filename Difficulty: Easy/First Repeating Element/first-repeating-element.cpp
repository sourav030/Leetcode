class Solution {
  public:
    int firstRepeated(vector<int> &arr) {
        // code here
        int ans=INT_MAX;
        unordered_map<int,int>mp;
        for(int i=0; i<arr.size(); i++){
            if(mp.find(arr[i])!=mp.end()){
                ans=min(ans,mp[arr[i]]);
            }
            mp[arr[i]]=i;
        }
        return ans==INT_MAX? -1: ans+1;
    }
};