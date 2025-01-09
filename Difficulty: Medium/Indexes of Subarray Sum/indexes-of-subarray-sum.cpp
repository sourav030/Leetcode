//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
            if(arr[i]==target){
                return {i+1,i+1};
            }
            if(sum==target){
                return {1,i+1};
            }
            int element=sum-target;
            if(mp.find(element)!=mp.end()){
                int x=mp[element]+2;
                return {x,i+1};
            }
            mp[sum]=i;
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends