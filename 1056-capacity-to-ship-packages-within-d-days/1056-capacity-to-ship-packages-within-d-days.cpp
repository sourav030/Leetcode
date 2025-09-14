class Solution {
public:
    bool isValid(vector<int>&weights, int day, int w){
        int d=1;
        int val=0;
        for(int i=0; i<weights.size(); i++){
            if(val+weights[i]>w){
                d++;
                val=weights[i];
            }
            else{
                val+=weights[i];
            }
            if(d>day){
                return false;
            }
        }
        return d<=day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN;
        int high=0;
        for(int i=0; i<weights.size(); i++){
            low=max(low,weights[i]);
            high+=weights[i];
        }

        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(weights,days,mid)){
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