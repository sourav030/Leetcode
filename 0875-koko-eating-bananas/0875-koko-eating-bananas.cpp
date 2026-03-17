class Solution {
public:
    int solve(vector<int>&piles, int k, int hour){
        int h=0;
        for(int i=0; i<piles.size(); i++){
            int banana=piles[i];
             h += (piles[i] + k - 1) / k;   

            if(h > hour) return false;
            if(h>hour){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=piles[0];
        for(int i=0; i<piles.size(); i++){
            high=max(high,piles[i]);
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};