//{ Driver Code Starts
// Initial Template for C++
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kthSmallest(vector<int>& arr, int k) {
        // code here
        priority_queue<int>pq;
        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }
        for(int i=k; i<arr.size(); i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    string line;

    // Read number of test cases
    getline(cin, line);
    t = stoi(line);

    while (t--) {
        // Read the array as a line of integers
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num);
        }

        // Read value of k
        getline(cin, line);
        int k = stoi(line);

        Solution sol;
        cout << sol.kthSmallest(arr, k) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends