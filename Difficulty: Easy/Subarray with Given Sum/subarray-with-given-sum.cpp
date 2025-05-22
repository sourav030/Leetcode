// User function Template for C++
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
   vector<int> subarraySum(vector<int>& arr, int sum) {
    int start = 0, end = 0;
    int Sum = 0;

    while (end < arr.size()) {
        Sum += arr[end];

        while (Sum > sum && start < end) {
            Sum -= arr[start];
            start++;
        }

        if (Sum == sum) {
            return {start + 1, end + 1}; // 1-based indexing
        }

        end++;
    }

    return {};
}

};