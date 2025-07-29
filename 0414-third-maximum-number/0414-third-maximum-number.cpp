class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>st;
        for(auto ele:nums){
            st.insert(ele);
        }
        vector<int>ans;
        for(auto ele:st){
            ans.push_back(ele);
        }

        int n=ans.size();
        return n>=3?ans[n-3]:ans[n-1];
    }
};