//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        vector<int>ans;
        for(int i=0; i<arr.size(); i++){
            int sum=arr[i];
            if(sum==target){
                ans.push_back(i+1);
                ans.push_back(i+1);
                return ans;
            }
            for(int j=i+1; j<arr.size();j++){
                sum+=arr[j];
                if(sum==target){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                   
                   return ans;
                    
                }
                
                if(sum > target){
                    sum=0;
                    
                    break;
                }
            }
        }
        ans.push_back(-1);
        return ans;
     
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore(); // Ignore the newline character after d

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