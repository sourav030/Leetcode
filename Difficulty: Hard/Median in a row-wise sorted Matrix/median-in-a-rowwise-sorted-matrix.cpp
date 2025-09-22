class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int>ans;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[i].size(); j++){
                ans.push_back(mat[i][j]);
            }
        }
        sort(ans.begin(), ans.end());
        int n=ans.size();
        if(n%2!=0){
            int indx=n/2;
            return ans[indx];
        }
        else{
            int idx1=n/2;
            int idx2=n/2+1;
            return (ans[idx1]+ans[idx2])/2;
        }
    }
};
