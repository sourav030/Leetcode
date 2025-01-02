//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:


// Function to find the index of the first element >= target in a sorted array
int findFirstGreaterOrEqual(vector<int> &arr, int target, int size) {
    int low = 0;
    int high = size - 1;
    int ans = size; // Default value if target not found
    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid overflow
        if (arr[mid] >= target) {
            ans = mid;      // Update answer
            high = mid - 1; // Search in the left half
        } else {
            low = mid + 1; // Search in the right half
        }
    }
    return ans;
}

// Function to find the row index with the maximum number of 1s in a binary matrix
int rowWithMax1s(vector<vector<int>> &arr) {
    int n = arr.size();    // Number of rows
    int m = arr[0].size(); // Number of columns
    int maxCount = 0;      // Maximum count of 1s found so far
    int rowIndex = -1;     // Row index with the maximum count of 1s

    for (int i = 0; i < n; i++) {
        int firstOneIndex = findFirstGreaterOrEqual(arr[i], 1, m); // Find the first occurrence of 1
        int countOfOnes = m - firstOneIndex; // Calculate the count of 1s in the current row

        if (countOfOnes > maxCount) { // If current row has more 1s
            maxCount = countOfOnes;
            rowIndex = i;
        }
    }
    return rowIndex; // Return the row index with the maximum 1s
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the integer input
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        cout << obj.rowWithMax1s(mat);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends