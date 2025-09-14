class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int ans=-1;
        int low=1;
        int end=m;
        while(low<=end){
            int mid=low+(end-low)/2;
            int val=pow(mid,n);
            if(val==m){
                return mid;
            }
            else if (val>m){
                end=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};