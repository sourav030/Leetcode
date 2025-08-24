class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
        int start=0;
        int end=0;
        unordered_set<char>st;
        int ans=0;
        while(end<nums.length()){
            if(st.find(nums[end])==st.end()){
                st.insert(nums[end]);
            }
            else{
                while(start<end and st.find(nums[end])!=st.end()){
                    st.erase(nums[start]);
                    start++;
                }
                st.insert(nums[end]);
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};