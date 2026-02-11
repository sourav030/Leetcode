class Solution {
  public:
    vector<vector<int>>ans;
    void solve(vector<int>&arr, int idx, vector<int>result){
        if(idx>=arr.size()){
            ans.push_back(result);
            return;
        }
        result.push_back(arr[idx]);
        solve(arr, idx+1,result);
        result.pop_back();
        solve(arr, idx+1,result);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        vector<int>result;
        int idx=0;
        solve(arr, idx, result);
        return ans;
        
    }
};