class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        
        int i=0;
        while(i<n){
            long long val=pow(3,i);
            if(val==n){
                return true;
            }
            if(val>n){
                return false;
            }
            i++;
        }
        return false;
    }
};