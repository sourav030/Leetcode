class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr;

        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first < b.first;
             });

        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int sum = arr[start].first + arr[end].first;

            if (sum == target) {
                return {arr[start].second, arr[end].second};
            }
            else if (sum > target) {
                end--;
            }
            else {
                start++;
            }
        }

        return {-1, -1};
    }
};