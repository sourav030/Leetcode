//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        stack<pair<int,int>>st;
        vector<int>ans;
        ans.push_back(1);
        st.push({arr[0],0});
        
        for(int i=1; i<arr.size(); i++){
            int count=0;
            while(!st.empty() && st.top().first<=arr[i]){
               count+= st.top().second;
                st.pop();
                count++;
            }
            st.push(make_pair(arr[i],count));
            ans.push_back(st.top().second+1);
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
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends