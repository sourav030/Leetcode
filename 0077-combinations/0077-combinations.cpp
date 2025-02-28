class Solution {
public:
    vector<vector<int>>result;
    void solve(int index,int k,int n, vector<int> &combination){
        if(combination.size()==k) result.push_back(combination);

        for(int i=index; i<=n;i++){
            combination.push_back(i);
            solve(i+1,k,n,combination);
            combination.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>combination;
        solve(1,k,n,combination);
        return result;
    }
};