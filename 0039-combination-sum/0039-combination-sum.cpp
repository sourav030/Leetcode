class Solution {
public:
    vector<vector<int>>result;

    void solve(int index,int target,vector<int>&arr,vector<int>&combination){
        if(target==0){
            result.push_back(combination);
            return;
        }
        if(index>=arr.size()){
            return;
        }
        if(arr[index]<=target){
            combination.push_back(arr[index]);
            solve(index,target-arr[index],arr,combination);
            combination.pop_back();
        }
        solve(index+1,target,arr,combination);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>combination;
        solve(0,target,candidates,combination);
        return result;
    }
};