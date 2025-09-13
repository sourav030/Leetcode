class Solution {
public:
    int findFloor(vector<int>& arr, int x) {
        int start = 0, end = arr.size() - 1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

          
            if (arr[mid] <= x) {
                ans = mid;      // candidate floor
                start = mid + 1;
            } 
            else {
                end = mid - 1;  // too big, go left
            }
        }
        return ans;
    }
};
