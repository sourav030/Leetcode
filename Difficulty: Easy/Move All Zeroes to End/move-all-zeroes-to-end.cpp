//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  void pushZerosToEnd(vector<int>& arr) {
    int zero = 0;

    // Count non-zero elements and collect them
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            temp.push_back(arr[i]); // Push non-zero elements
        } else {
            zero++; // Count zeros
        }
    }

    // Fill the original array with non-zero elements
    for (int i = 0; i < temp.size(); i++) {
        arr[i] = temp[i];
    }

    // Fill the remaining positions with zeros
    for (int i = temp.size(); i < arr.size(); i++) {
        arr[i] = 0;
    }
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends