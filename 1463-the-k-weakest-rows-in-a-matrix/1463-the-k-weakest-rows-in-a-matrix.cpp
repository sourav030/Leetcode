class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<pair<int,int>>arr;
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<m; j++){
                if(mat[i][j]==1){
                    count++;
                }
                else{
                    break;
                }
            }
            arr.push_back({count,i});
        }
        vector<int>ans;
        sort(arr.begin(),arr.end());
        for(int i=0; i<k; i++){
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};