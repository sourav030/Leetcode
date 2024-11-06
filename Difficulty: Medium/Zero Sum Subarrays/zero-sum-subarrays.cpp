//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
      unordered_map<int,int> mp;
      int sum=0;
      int total=0;
      mp[0]=1;
      for(int i=0; i<arr.size(); i++){
        sum+=arr[i];
        if(mp.count(sum)){
            total+=mp[sum];
            mp[sum]++;
        }   
        else{
            mp[sum]++;
        }
      }
      return total;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.findSubarray(arr) << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends