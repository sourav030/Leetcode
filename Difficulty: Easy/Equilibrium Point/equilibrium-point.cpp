//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        vector<int>prefix;
        int sum=0;
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
            prefix.push_back(sum);
        }
        int n=prefix.size();
        int total_sum=prefix[n-1];
        for(int i=1; i<n; i++){
            int left=prefix[i-1];
            int right=total_sum-prefix[i];
            if(left==right){
                return i;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends