class Solution {
public:

    bool solve(vector<int>& arr, int weight, int Day){
        int loadWeight=0;
        int day=1;
        for(int i=0; i<arr.size(); i++){
            if(loadWeight+arr[i]>weight){
                day++;
                loadWeight=arr[i];
            }
            else{
                loadWeight+=arr[i];
            }
        }
        if(day<=Day){
            return 1;
        }
        else{
            return 0;
        }
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
            if(solve(weights,mid,days)){
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