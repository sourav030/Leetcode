//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int product=1;
        int zeroCount=0;
        int n=arr.size();
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==0){
                zeroCount++;
            }
            else{
                product*=arr[i];
            }
        }
        
        if(zeroCount>1){
            vector<int>ans(n,0);
            return ans;
        }
        else if (zeroCount==1){
            for(int i=0; i<arr.size();i++){
                if(arr[i]==0){
                    arr[i]=product;
                }
                else{
                    arr[i]=0;
                }
            }
            return arr;
        }
        
        else{
            for(int i=0; i<arr.size(); i++){
                arr[i]=product/arr[i];
            }
            return arr;
        }
        
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends