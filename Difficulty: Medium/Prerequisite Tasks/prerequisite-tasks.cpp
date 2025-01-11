//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& arr) {
        // Code here
        vector<vector<int>> adj(N);
        for(int i=0; i<P; i++){
            adj[arr[i].first].push_back(arr[i].second);
        }
        
        vector<int>indegre(N,0);
        for(int i=0; i<N; i++){
            for(auto ele:adj[i]){
                indegre[ele]++;
            }
        }
        
        queue<int>q;
        
        for(int i=0; i<N; i++){
            if(indegre[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto ele: adj[node]){
                indegre[ele]--;
                if(indegre[ele]==0){
                    q.push(ele);
                }
            }
        }
        
        return indegre.size()==count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends