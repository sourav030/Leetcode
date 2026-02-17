class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(!st.empty() and arr[i]>arr[st.top()]){
                ans[i]=arr[st.top()];
            }
            st.push(i);
        }
        return ans;
    }
};