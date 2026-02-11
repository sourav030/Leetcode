class Solution {
  public:
    void solve(int idx, int n){
        if(idx>n){
            return;
        }
        cout<<idx<<" ";
        solve(idx+1,n);
    }
    void printTillN(int n) {
        // code here
        int idx=1;;
        solve(idx,n);
    }
};