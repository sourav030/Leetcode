class Solution {
  public:
    // Function to return kth largest element from an array.
    int KthLargest(vector<int> &arr, int k) {
        // Your code here
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        return arr[k-1];
    }
};