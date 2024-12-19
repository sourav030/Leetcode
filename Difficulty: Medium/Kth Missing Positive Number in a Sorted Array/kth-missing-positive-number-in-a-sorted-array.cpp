//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        vector<int>ans;
        int i=1;
        int j=0;
        int n=arr.size();
        while(j<n){
            if(arr[j]==i){
                i++;
                j++;
            }
            else{
                ans.push_back(i);
                i++;
            }
           
        }
        
        int m=ans.size();
        if(m==0){
            return arr[n-1]+k;
        }
          if(k>m){
            k=k-m;
             return arr[n-1]+k;
        }
        
        else{
            return ans[k-1];
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends