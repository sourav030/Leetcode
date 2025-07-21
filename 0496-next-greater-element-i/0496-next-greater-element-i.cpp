class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int n2=nums2.size();
        vector<int>ans(n,-1);
        vector<int>nextGreater(n2,-1);
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[nums1[i]]=i;
        }
     
        stack<int>st;

        for(int i=n2-1; i>=0; i--){
            while(!st.empty() and nums2[st.top()]<nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                nextGreater[i]=nums2[st.top()];
            }
            st.push(i);
        }

        for(int i=0; i<nums2.size(); i++){
            if(mp.find(nums2[i])!=mp.end()){
                int index=mp[nums2[i]];
                ans[index]=nextGreater[i];
            }
        }
        return ans;

    }
};