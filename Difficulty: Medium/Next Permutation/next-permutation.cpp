//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
        // code here
        int n=nums.size(), i,j;
        for( i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        
        if(i>=0){
            for(j=n-1; j>=i; j--){
                if(nums[j] > nums[i]){
                    break;
                }
            }
            swap(nums[i],nums[j]);
        }
        
        reverse(nums.begin()+1+i, nums.end());
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
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends