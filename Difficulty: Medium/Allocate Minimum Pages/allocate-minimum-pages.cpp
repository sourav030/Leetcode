class Solution {
  public:
   bool solve(vector<int>& arr, int page, int k) {
       int count = 1;      // at least one student
       int currPage = 0;

       for (int i = 0; i < arr.size(); i++) {
           if (arr[i] > page) {
               return false;   // impossible if a single book exceeds limit
           }
           if (currPage + arr[i] > page) {
               count++;        // allocate to next student
               currPage = arr[i];
           } else {
               currPage += arr[i];
           }
       }
       return count <= k;   // must not exceed k students
   }

    int findPages(vector<int> &arr, int k) {
        if (arr.size() < k) return -1;  // not enough books

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(arr, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
