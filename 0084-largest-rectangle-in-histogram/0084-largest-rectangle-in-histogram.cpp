class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nextSmaller(n,n);
        vector<int>prevSmaller(n,-1);
        stack<int>st;
        for(int i=n-1; i>=0; i--){

            while(!st.empty() and heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(!st.empty() and heights[i]>heights[st.top()]){
                nextSmaller[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=0; i<n; i++){
             while(!st.empty() and heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(!st.empty() and heights[i]>heights[st.top()]){
                prevSmaller[i]=st.top();
            }
            st.push(i);
        }
        int ans=INT_MIN;
        for(int i=0; i<heights.size(); i++){
            int h=heights[i];
            int w=nextSmaller[i]-prevSmaller[i]-1;
            ans=max(ans,h*w);
        }
        return ans;
    }
};