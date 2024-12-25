//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>has(n+1,0);
        for(int i=0; i<arr.size(); i++ ){
            has[arr[i]]++;
        }
        int repeating=-1;
        int missing=-1;
        for (int i = 1; i <= n; i++) { // Loop from 1 to n
        if (has[i] == 2) {
            repeating = i;
        } else if (has[i] == 0) {
            missing = i;
        }
        if (repeating != -1 && missing != -1) {
            break;
        }
    }
        return { repeating,missing};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends