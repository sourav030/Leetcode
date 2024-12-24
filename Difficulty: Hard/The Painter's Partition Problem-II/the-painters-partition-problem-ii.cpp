//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  bool isValid(vector<int>& arr, int k,int n, int maxAlloc){
      int time=0;
      int painter=1;
      for(int i=0;i<n; i++){
          if(arr[i]>maxAlloc){
              return false;
          }
          if(time+arr[i]<=maxAlloc){
              time+=arr[i];
          }
          else{
              painter++;
              time=arr[i];
          }
          if(painter>k){
              return false;
          }
      }
          return true;
  }
    int minTime(vector<int>& arr, int k) {
        // code here
        // return minimum time
        int minimum=INT_MIN;
        int maximum=0;
        int n=arr.size();
        int ans=-1;
        for(int i=0; i<arr.size(); i++){
            minimum=max(minimum,arr[i]);
            maximum+=arr[i];
        }
        while(minimum<=maximum){
            int mid=minimum+(maximum-minimum)/2;
            if(isValid(arr,k,n,mid)){
                maximum=mid-1;
                ans=mid;
            }
            else{
                minimum=mid+1;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends