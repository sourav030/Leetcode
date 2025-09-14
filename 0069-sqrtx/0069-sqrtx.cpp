class Solution {
public:
    int mySqrt(int x) {
        int ans=1;
        if(x==0){
            return 0;
        }
        for(int i=1; i<x; i++){
            if(pow(i,2)<=x){
                ans=i;
            }
            else{
                break;
            }
        }
        return ans;
    }
};