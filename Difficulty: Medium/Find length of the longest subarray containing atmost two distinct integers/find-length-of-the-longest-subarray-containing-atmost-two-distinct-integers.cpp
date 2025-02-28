//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int,int>mp;
        int left=0;
        int right=0;
        int maxLen=0;
        while(right<arr.size()){
            mp[arr[right]]++;
            if(mp.size()>2){
                mp[arr[left]]--;
                if(mp[arr[left]]==0) mp.erase(arr[left]);
                left++;
            }
            if(mp.size()<=2){
                maxLen=max(maxLen,right-left+1);
            }
            right++;
            
        }
        return maxLen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends