class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        int idx=0;
        while(idx<numRows){
            vector<int>arr(idx+1,1);
            int start=0;
            int end=arr.size()-1;
            arr[start]=arr[end]=1;
            for(int i=1; i<end; i++){
                arr[i]=ans[idx-1][i-1]+ans[idx-1][i];
            }
            ans.push_back(arr);
            idx++;
        }
        return ans;
    }
};