//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int commanDifference=arr[1]-arr[0];
        int prev=arr[0];
        for(int i=1; i<arr.size(); i++){
            if(prev+commanDifference==arr[i]){
                prev=arr[i];
            }
            else{
                return prev+commanDifference;
            }
        }
        int n=arr.size();
        return arr[n-1]+commanDifference;
        
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
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends