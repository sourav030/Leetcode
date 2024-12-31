class Solution {
public:
    int find(vector<int>&arr,int time){
        int total=0;
        for(int i=0; i<arr.size(); i++){
            total += (int)ceil((double)arr[i] / time);
        }
       return total;

    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int low=1;
        int heigh=INT_MIN;
        for(int i=0; i<arr.size(); i++){
            heigh=max(heigh,arr[i]);
        }
        int ans=heigh;
        while(low<=heigh){
            int mid=low+(heigh-low)/2;
            int totalHour=find(arr,mid);
            if(totalHour<=h){
                ans=mid;
                heigh=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};