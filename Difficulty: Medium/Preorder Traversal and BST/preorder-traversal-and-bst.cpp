//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    void check(int arr[], int &index, int lower, int upper, int n){
        if(index==n or arr[index]< lower or arr[index] > upper)
        return;
        int val=arr[index++];
        // for left side
        check(arr, index, lower,val,n);
        check(arr, index, val, upper,n);
    }
  public:
    int canRepresentBST(int arr[], int N) {
        // code here
        int index=0;
        check(arr, index, INT_MIN, INT_MAX, N);
        return index==N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends