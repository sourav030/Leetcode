class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x==1) return x;
        int low=1;
        int high=x;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(pow(mid,2)>x){
                high=mid-1;
            }
            else if(pow(mid,2)==x){
                return mid;
            }
            else{
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
};