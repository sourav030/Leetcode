class Solution {
public:
    bool increase(vector<int>&num){
        for(int i=1; i<num.size(); i++){
            if(num[i]<num[i-1]){
                return false;
            }
        }
        return true;
    }
    bool decrease(vector<int>&num){
        for(int i=1; i<num.size(); i++){
            if(num[i]>num[i-1]){
                return false;
            }
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {
        return increase(nums) || decrease(nums);
    }
};