//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int i=0;
        int j=0;
        int count=0;
        int ans=0;
        while(j<arr.size()){
            if(arr[j]==0){
                count++;
            }
            while(count>k){
                if(arr[i]==0){
                    count--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
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
        int m;
        cin >> m;
        cin.ignore();

        Solution obj;
        int ans = obj.maxOnes(arr, m);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends