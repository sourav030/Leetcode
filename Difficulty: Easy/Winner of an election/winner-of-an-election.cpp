//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return the name of candidate that received maximum votes.
    vector<string> winner(vector<string> &arr) {
        // code 
        map<string,int>mp;
        for(int i=0; i<arr.size();  i++){
            mp[arr[i]]++;
        }
        int maxi=INT_MIN;
        string name="";
        for(auto ele:mp){
            if(maxi<ele.second){
                maxi=ele.second;
                name=ele.first;
            }
        }
         string m=to_string(maxi);
        return {name,m};
        
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    string s;
    vector<string> res;
    while (ss >> s) {
        res.push_back(s);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {
        vector<string> arr = inputLine();
        Solution obj;
        vector<string> result = obj.winner(arr);

        cout << result[0] << " " << result[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends