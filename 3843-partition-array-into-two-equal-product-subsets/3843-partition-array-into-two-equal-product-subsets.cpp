class Solution {
public:
    bool solve(vector<int>&nums, long long target, int idx, long long mul){
        if(mul==target){
            
            return true;
        }
        if(idx>=nums.size()){
            return false;
        }
        bool take=solve(nums,target,idx+1,mul*nums[idx]);
        bool notTake=solve(nums,target,idx+1,mul);
        return take||notTake;
        
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        long double multiply=1;
        for(int i=0; i<nums.size(); i++){
            multiply=multiply*nums[i];
        }
        if(target!=multiply/target){
            return false;
        }
        int idx=0;
        long long mul=1;
        return (nums,target,idx , mul);
    }
};