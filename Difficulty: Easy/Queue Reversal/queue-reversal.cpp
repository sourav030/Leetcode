//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// function Template for C++

class Solution {
  public:
    
    void solve(queue<int>&q, int n){
        if(n==0) return;
        int x=q.front();
        q.pop();
        solve(q,n-1);
        q.push(x);
    }
    queue<int> reverseQueue(queue<int> &q) {
        // code here.
        int n=q.size();
        solve(q,n);
        return q;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input

    while (t--) {
        vector<int> inputArray;
        string input;

        // Input format: First number is 'n', followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int element;

        // Parse the input and populate the vector
        while (ss >> element) {
            inputArray.push_back(element);
        }

        int n = inputArray.size(); // Number of elements in the array
        queue<int> q;
        int i = 0;

        // Push all elements from the input array into the queue
        while (n--) {
            int value = inputArray[i++];
            q.push(value);
        }

        // Create an object of the Solution class and call the reverseQueue function
        Solution solution;
        queue<int> reversedQueue = solution.reverseQueue(q);

        // Output the reversed queue
        while (!reversedQueue.empty()) {
            cout << reversedQueue.front()
                 << " ";         // Print the front element of the queue
            reversedQueue.pop(); // Remove the front element from the queue
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends