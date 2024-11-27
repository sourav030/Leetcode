//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        sort(arr.begin(),arr.end());
        set<int> myset;
        for(int i=0; i< arr.size(); i++){
            myset.insert(arr[i]);
        }
        int j=0;
        vector<int>ans;
        for(int a:myset){
            ans.push_back(a);
        }
        int x=1;
        for(int i=0; i<ans.size(); i++){
            if(ans[i]<=0){
                continue;
            }
            if(ans[i]==x){
                x++;
            }
            else{
                return x;
            }
        }
        return x;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends