class Solution {
public:
    bool check(vector<int>& nums, int mid, int threshold){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += (nums[i] + mid - 1) / mid;
        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(check(nums, mid, threshold)){
                ans = mid;
                high = mid - 1; 
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};