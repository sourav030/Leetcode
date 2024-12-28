//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {

        // your code here
        unordered_map<int,int>mp;
        for(int i=0; i<arr.size(); i++){
            if(mp.find(arr[i])!=mp.end()){
                mp[arr[i]]++;
            }
            else{
                mp[arr[i]]=1;
            }
        }
        
        int n=arr.size();
        
        for(auto x:mp){
            if(x.second>n/2){
                return x.first;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}

// } Driver Code Ends