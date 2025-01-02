//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool isPossible(vector<int> &arr, int k, int page){
        int current=0;
        int student=1;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>page){
                return false;
            }
            if(current+arr[i]<=page){
                current+=arr[i];
            }
            else{
                student++;
                current=arr[i];
            }
        }
        return student<=k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
       
        int n=arr.size();
        if(n<k){
            return -1;
        }
        int low=0;
        int high=0;
        for(int i=0; i<arr.size(); i++){
            high+=arr[i];
            low=max(low,arr[i]);
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(arr,k,mid)){
                ans=mid;
                high=mid-1;
                
            }
            else{
                low=mid+1;
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