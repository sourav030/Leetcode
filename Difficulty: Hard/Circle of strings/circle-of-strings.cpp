//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
 void DFS(int node, vector<int>adj[], vector<bool>& visited){
     visited[node]=1;
     
     for(int j=0; j<adj[node].size(); j++){
         if(!visited[adj[node][j]]){
             DFS(adj[node][j],adj, visited);
         }
     }
 }
    int isCircle(vector<string> &arr) {
        // code here
        
        // edges create krna
        //adjacency list
        vector<int>adj[26];
        int N=arr.size(); 
        vector<int>InDeg(26,0);
        vector<int>OutDeg(26,0);
        for(int i=0; i<N; i++){
            string temp=arr[i];
            int u=temp[0]-'a';
            int v=temp[temp.size()-1]-'a';
            adj[u].push_back(v);
            OutDeg[u]++;
            InDeg[v]++;
        }
        
        //Eluerian circuit
        // if indegree and outdegree
        for(int i=0; i<26; i++){
            if(InDeg[i]!=OutDeg[i]){
                return 0;           
            }
        }
        
        vector<bool>visited(26,0);
        // all edges are the partof compenent
        DFS(arr[0][0]-'a',adj,visited);
        
        for(int i=0; i<26; i++){
            if(InDeg[i] and !visited[i]){
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends