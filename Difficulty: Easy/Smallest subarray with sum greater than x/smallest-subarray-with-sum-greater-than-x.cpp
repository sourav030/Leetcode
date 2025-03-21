//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int left=0;
        int right=0;
        int ans=INT_MAX;
        int sum=0;
        while(right<arr.size()){
            sum+=arr[right];
            if(arr[right]>x){
                ans=1;
            }
            while(sum>x and left!=right){
                if( left!=right)
                ans=min(ans,right-left+1);
                sum-=arr[left];
                left++;
            }
            right++;
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        vector<int> arr;
        int x;

        cin >> x;
        cin.ignore(); // Ignore the newline character after x

        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        cout << obj.smallestSubWithSum(x, arr) << "\n~\n";
    }

    return 0;
}
// } Driver Code Ends