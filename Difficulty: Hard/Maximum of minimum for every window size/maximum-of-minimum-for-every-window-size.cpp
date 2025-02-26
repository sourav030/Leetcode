//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
   vector<int> maxOfMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n, -1), right(n, n);  // PSE and NSE
    stack<int> s;
    
    // Finding Previous Smaller Element (PSE)
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (!s.empty())
            left[i] = s.top();
        s.push(i);
    }

    while (!s.empty()) s.pop();  // Clear stack for next computation

    // Finding Next Smaller Element (NSE)
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (!s.empty())
            right[i] = s.top();
        s.push(i);
    }

    // Create an array to store max of mins for each window size
    vector<int> res(n + 1, 0);

    // Fill result array using window size calculation
    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1;  // Window size in which arr[i] is minimum
        res[len] = max(res[len], arr[i]);
    }

    // Fill the missing values from right to left
    for (int i = n - 1; i >= 1; i--) {
        res[i] = max(res[i], res[i + 1]);
    }

    res.erase(res.begin());  // Remove the 0th index

    return res;
}

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends