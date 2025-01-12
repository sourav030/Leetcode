//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>leftmax(n,0);
        int maximum=arr[0];
        for(int i=0; i<n; i++){
            maximum=max(maximum,arr[i]);
            leftmax[i]=maximum;
        }
        
        maximum=arr[n-1];
        vector<int>rightmax(n);
        for(int i=n-1; i>=0; i--){
            maximum=max(maximum,arr[i]);
            rightmax[i]=maximum;
        }
        
        int ans=0;
        for(int i=0; i<n; i++){
            int mini=min(leftmax[i],rightmax[i]);
            int store=mini-arr[i];
           
            if(store>=0){
                ans+=store;
            }
        }
        return ans;
        
        
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends