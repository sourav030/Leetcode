class Solution {
  public:
    int solve(vector<int>&hight){
        int n=hight.size();
        vector<int>prevSmaller(n,0);
        vector<int>nextSmaller(n,n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and hight[st.top()]>=hight[i]){
                st.pop();
            }
            if(st.empty()){
                nextSmaller[i]=n;
            }
            else{
                nextSmaller[i]=st.top();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=0; i<n; i++){
            while(!st.empty() and hight[st.top()]>=hight[i]){
                st.pop();
            }
            if(st.empty()){
                prevSmaller[i]=-1;
            }
            else{
                prevSmaller[i]=st.top();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(hight[i]!=0){
                ans=max(ans,(nextSmaller[i]-prevSmaller[i]-1)*hight[i]);
            }
        }
        return ans;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int row=mat.size();
        int col=mat[0].size();
        vector<int>hight(col,0);
        int ans=0;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                hight[j]=mat[i][j]==0?0: hight[j]+1;
            }
            ans=max(ans,solve(hight));
        }
        return ans;
    }
};