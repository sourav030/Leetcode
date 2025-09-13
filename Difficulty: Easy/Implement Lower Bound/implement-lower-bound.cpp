class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int start = 0;
        int end = arr.size() - 1;
        int ans = arr.size(); // default: if target > all elements

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] >= target) {
                ans = mid;       // possible answer, but check left side
                end = mid - 1;
            } else {
                start = mid + 1; // move right
            }
        }
        return ans;
    }
};
