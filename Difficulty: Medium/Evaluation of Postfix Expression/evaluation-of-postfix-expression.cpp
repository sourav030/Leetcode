//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int>st;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]!="+" and arr[i]!="-" and arr[i]!="*" and arr[i]!="/"){
                int ele=stoi(arr[i]);
                st.push(ele);
            }
            else{
                if(arr[i]=="+"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    st.push(b+a);
                }
                else if (arr[i]=="-"){
                    
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    st.push(b-a);
                    
                }
                else if(arr[i]=="*"){
                    
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                   st.push(b*a);
                    
                }
                else if (arr[i]=="/"){
                    
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    st.push(b/a);
                    
                }
            }
        }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends