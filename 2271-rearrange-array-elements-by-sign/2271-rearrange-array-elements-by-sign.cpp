class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>postive;
        vector<int>negative;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                negative.push_back(nums[i]);
            }
            else{
                postive.push_back(nums[i]);
            }
        }
        vector<int>result;
        int n=postive.size();
        int m=negative.size();
        bool chance=0;
        int i=0;
        int j=0;
        while(i<n and j<m){
            if(chance==0){
                result.push_back(postive[i]);
                i++;
                chance=1;
            }
            else{
                result.push_back(negative[j]);
                j++;
                chance=0;

            }
        }
        while(i<n){
            result.push_back(postive[i]);
            i++;
        }
        while(j<m){
            result.push_back(negative[j]);
                j++;
        }
        return result;
    }
};