//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int binarySearch(vector<int> &arr, int complement) {
        int lo = 0, hi = arr.size() - 1;
        int res = arr.size();

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (arr[mid] >= complement) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    }

    int countPairs(vector<int> &arr, int target) {
        int cnt = 0;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            int complement = target - arr[i];
            int ind = binarySearch(arr, complement);
            cnt += ind;

            if (ind > i)
                cnt--;
        }

        return cnt / 2;
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends