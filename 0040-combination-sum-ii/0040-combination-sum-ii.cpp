class Solution {
public:
    vector<vector<int>> result;

    void solve(int index, vector<int>& combination, int target, vector<int>& arr) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        if (index >= arr.size() || target < 0) return;

        // Pick the element
        if (arr[index] <= target) {
            combination.push_back(arr[index]);
            solve(index + 1, combination, target - arr[index], arr);
            combination.pop_back(); // Backtrack
        }

        // Skip duplicate elements
        while (index + 1 < arr.size() && arr[index] == arr[index + 1]) {
            index++;
        }

        // Not pick the element
        solve(index + 1, combination, target, arr);
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end()); // Sorting to handle duplicates
        vector<int> combination;
        result.clear();
        solve(0, combination, target, arr);
        return result;
    }
};
