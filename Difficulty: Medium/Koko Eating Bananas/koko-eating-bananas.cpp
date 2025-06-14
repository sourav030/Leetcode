class Solution {
  public:
    bool check(vector<int>& piles, int speed, int h) {
        int hours = 0;
        for (int bananas : piles) {
            hours += (bananas + speed - 1) / speed;  // ceil(bananas/speed)
        }
        return hours <= h;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low=1;
        int high=0;
        for(int i=0; i<arr.size(); i++){
            high=max(high,arr[i]);
        }
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(arr,mid,k)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};