class Solution {
public:

    vector<vector<int>>result;

    void solve(int index,int k,int n, vector<int>&ans){
        if(ans.size()==k and n==0){
            result.push_back(ans);
            return;
        }
        if(index>9 ){
            return;
        }
        ans.push_back(index);
        solve(index+1,k,n-index ,ans);
        ans.pop_back();
        solve(index+1,k,n,ans);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ans;
        solve(1,k,n,ans);
        return result;
    }
};