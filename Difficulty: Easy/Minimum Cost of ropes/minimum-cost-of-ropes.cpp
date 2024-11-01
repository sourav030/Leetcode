//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        priority_queue<long long , vector<long long>, greater<long long> > q;
        for(long long i=0; i< arr.size(); i++){
            q.push(arr[i]);
        }
        
       long long cost=0;
        while(q.size()>1){
           long long rope=q.top();
           q.pop();
           rope+=q.top();
           q.pop();
           cost+=rope;
           q.push(rope);
        }
      return  cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends