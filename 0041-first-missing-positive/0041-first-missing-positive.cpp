class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        vector<int>nums1(st.begin(),st.end());
        sort(nums1.begin(),nums1.end());
        int start=1;
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]<=0){
                continue;
            }
            if(nums1[i]==start){
                start++;
            }
            else{
                return start;
            }
        }
        return start;

    }
};