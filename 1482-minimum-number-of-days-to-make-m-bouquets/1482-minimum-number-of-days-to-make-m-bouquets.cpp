class Solution {
public:

    bool solve(vector<int>& bloomDay, int m, int k, int day){
        int count = 0;
        int b = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                count++;
            }
            else{
                count = 0;
            }

            if(count == k){
                b++;
                count = 0;
            }
        }

        return b >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        if((long long)m * k > bloomDay.size())
            return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(solve(bloomDay, m, k, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};