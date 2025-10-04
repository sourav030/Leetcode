class Solution {
  public:
    vector<int>ans;
    void solve(vector<int>arr, int sum, int index){
        if(index>=arr.size()){
            ans.push_back(sum);
            return;
        }
        sum=sum+arr[index];
        solve(arr, sum, index+1);
        sum=sum-arr[index];
        solve(arr, sum, index+1);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        solve(arr, 0, 0);
        return ans;
    }
};