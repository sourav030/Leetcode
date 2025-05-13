//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int>st;
        for(int i=0; i<asteroids.size(); i++){
             bool destroyed = false;
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0){
                 int top = st.top();
                if (abs(top) < abs(asteroids[i])) {
                    st.pop(); 
                } else if (abs(top) == abs(asteroids[i])) {
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                  
                    destroyed = true;
                    break;
                }
            }
            
            if(!destroyed) st.push(asteroids[i]);
            
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends