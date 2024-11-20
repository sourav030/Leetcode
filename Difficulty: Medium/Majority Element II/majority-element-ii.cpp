//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++)
        {
            mp[arr[i]]++;
        }
        vector<int>ans;
        int x=INT_MIN;
        for(int i=0; i<arr.size(); i++){
            if(x==arr[i]){
                continue;
            }
           if(mp[arr[i]] > n/3){
               ans.push_back(arr[i]);
               x=arr[i];
           }
        } 
        sort(ans.begin(),ans.end());
       
      
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends