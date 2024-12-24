//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isValid(vector<int> &arr, int n, int k, int maxAlloc){
        int student=1;
        int page=0;
        for(int i=0; i<n; i++){
            if(arr[i]>maxAlloc){
                return false;
            }
            if(page+arr[i]<=maxAlloc){
                page+=arr[i];
            }
            else{
                student++;
                page=arr[i];
            }
             if (student > k) {
                return false; // Too many students required
            }
        }
        return true;;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k> arr.size()){
            return -1;
        }
        int start=0;
        int end=0;
        for(int i=0; i<arr.size(); i++){
            end+=arr[i];
        }
        int n=arr.size();
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isValid(arr,n,k,mid)){
                end=mid-1;
                ans=mid;
            }
            else{
                start=mid+1;
            }
            
        }
        return ans;
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
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends