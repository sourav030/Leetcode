class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,-1);
        int maxi=INT_MIN;
        for(int i=arr.size()-1; i>=0; i--){
            if(maxi==INT_MIN){
                ans[i]=-1;
            }
            else{
                ans[i]=maxi;
            }
            maxi=max(maxi,arr[i]);
            
        }
        return ans;
    }
};