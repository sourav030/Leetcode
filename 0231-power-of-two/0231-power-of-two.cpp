class Solution {
public:
    int solve(int n){
        if(n==1){
            return true;
        }
        if(n<1 or n%2!=0){
            return false;
        }
        return solve(n/2);
    }
    bool isPowerOfTwo(int n) {
       return solve(n);
    }
};