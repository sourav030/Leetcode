//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    queue<int>q;
	    for(int i=0; i<V; i++){
	        if(color[i]==-1){
	            color[i]=0;
	            q.push(i);
	            while(!q.empty()){
	                int Node=q.front();
	                q.pop();
	                for(int i=0; i<adj[Node].size(); i++){
	                    if(color[adj[Node][i]]==-1){
	                        color[adj[Node][i]]=(color[Node]+1)%2;
	                        q.push(adj[Node][i]);
	                    }
	                    else {
	                        if(color[Node]==color[adj[Node][i]]){
	                            return 0;
	                        }
	                    }
	                }
	            }
	        }
	    }
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends