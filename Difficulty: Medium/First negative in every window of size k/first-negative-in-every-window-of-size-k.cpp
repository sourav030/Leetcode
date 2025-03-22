//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        vector<int>ans;
        vector<int>subarray;
        int zero=0;
        for(int i=0; i<k; i++){
            if(arr[i]<0 and zero==0){
                zero=arr[i];
            }
            subarray.push_back(arr[i]);
        }
        ans.push_back(zero);
        
        for(int i=k; i<arr.size(); i++){
            subarray.push_back(arr[i]);
            subarray.erase(subarray.begin());
            
            zero=0;
            for(int i=0; i<subarray.size(); i++){
                if(subarray[i]<0){
                    zero=subarray[i];
                    break;
                }
            }
            ans.push_back(zero);
            
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.FirstNegativeInteger(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends