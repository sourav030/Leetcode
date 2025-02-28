class Solution {
public:
    vector<vector<int>>ans;
    void solve(int index,vector<int>&num){
        if(index==num.size()){
            ans.push_back(num);
            return;
        }
        for(int i=index;i<num.size(); i++){
            swap(num[i],num[index]);
            solve(index+1,num);
            swap(num[i],num[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        solve(0,nums);
        return ans;
    }
};