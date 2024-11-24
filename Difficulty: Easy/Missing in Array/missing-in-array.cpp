//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        if(n==1 and arr[0]==1){
            return 2;
        }
        vector<int>ans(n+1,-1);
        for(int i=0; i<arr.size(); i++){
            ans[arr[i]-1]=arr[i];
        }
        int a;
        for(int i=0; i<n+1; i++){
            if(ans[i]==-1){
                a=i+1;
            }
        }
        return a;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNumber(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends