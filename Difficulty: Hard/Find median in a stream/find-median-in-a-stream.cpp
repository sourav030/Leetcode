//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> low; // Max Heap
        priority_queue<int, vector<int>, greater<int>> high; // Min Heap
        vector<double> medians;
        
        for (int num : arr) {
            // Insert into max heap (low) if empty or num <= max of low
            if (low.empty() || num <= low.top()) {
                low.push(num);
            } else {
                high.push(num);
            }

            // Balance the heaps
            if (low.size() > high.size() + 1) {
                high.push(low.top());
                low.pop();
            } else if (high.size() > low.size()) {
                low.push(high.top());
                high.pop();
            }

            // Compute median
            if (low.size() > high.size()) {
                medians.push_back(low.top());
            } else {
                medians.push_back((low.top() + high.top()) / 2.0);
            }
        }
        
        return medians;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends