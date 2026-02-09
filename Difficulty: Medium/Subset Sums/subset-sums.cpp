class Solution {
  public:
  
   vector<int>ans;
   void solve(vector<int>&arr, int idx, int sum){
       if(idx>=arr.size()){
           ans.push_back(sum);
           return ;
       }
       // take the element
       solve(arr,idx+1,sum+arr[idx]);
       // not take the element
       solve(arr, idx+1, sum);
   }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int sum=0;
        int idx=0;
        solve(arr, idx, sum);
        return ans;
    }
};