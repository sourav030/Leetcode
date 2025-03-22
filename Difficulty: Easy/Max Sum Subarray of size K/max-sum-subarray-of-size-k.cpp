//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        
        int sum=0;
         int maxSum=0;
        for(int i=0; i<k; i++){
            sum+=arr[i];
            
        }
        maxSum=sum;
        int left=0;
        for(int i=k; i<arr.size(); i++ ){
            sum+=arr[i];
            sum-=arr[left];
            left++;
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.maximumSumSubarray(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends