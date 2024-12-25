class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){

            // aga
            if(ans.empty() or arr[i][0] > ans.back()[1]){
                ans.push_back(arr[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],arr[i][1]);
            }
        }
        return ans;
    }
};