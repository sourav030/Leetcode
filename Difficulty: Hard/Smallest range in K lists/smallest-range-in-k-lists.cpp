//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k = arr.size();
        int n = arr[0].size();

        // Min heap: (value, row index, column index)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        int maxVal = INT_MIN;
        for (int i = 0; i < k; ++i) {
            minHeap.push({arr[i][0], i, 0});
            maxVal = max(maxVal, arr[i][0]);
        }

        int range = INT_MAX;
        int start = -1, end = -1;

        while (minHeap.size() == k) {
            auto curr = minHeap.top();
            minHeap.pop();
            int minVal = curr[0], row = curr[1], col = curr[2];

            if (maxVal - minVal < range) {
                range = maxVal - minVal;
                start = minVal;
                end = maxVal;
            }

            if (col + 1 < arr[row].size()) {
                int nextVal = arr[row][col + 1];
                minHeap.push({nextVal, row, col + 1});
                maxVal = max(maxVal, nextVal);
            } else {
                break;
            }
        }

        return {start, end};
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends