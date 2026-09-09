class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        ans.push_back({1});

        int idx = 1;

        while (idx <= rowIndex) {
            vector<int> arr(idx + 1);
            arr[0] = 1;
            arr[arr.size() - 1] = 1;

            for (int i = 1; i < arr.size() - 1; i++) {
                int sum = ans[idx - 1][i] + ans[idx - 1][i - 1];
                arr[i] = sum;
            }

            ans.push_back(arr);
            idx++;
        }

        return ans[rowIndex];
    }
};