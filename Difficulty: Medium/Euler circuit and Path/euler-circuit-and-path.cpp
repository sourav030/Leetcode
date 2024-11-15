//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void  Dfs(int Node, vector<int>adj[], vector<bool> &visited){
        visited[Node]=1;
        for(int i=0; i<adj[Node].size(); i++){
            int neighbour=adj[Node][i];
            if(!visited[neighbour]){
                Dfs(neighbour,adj,visited);
            }
        }
    }
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	    // Euler circuit condition
	    // calculate the degree of all node
	    // all node should have even degree
	    // all non zero degree node should be connected
	    
	     // Code here
	    // Euler path condition
	    // calculate the degree of all node
	    // all node should have even degree and 2 have odd degree
	    // all non zero degree node should be connected
	    
	    vector<int>Deg(V,0);
	    
	    int odd_Degree=0;
	    
	    for(int i=0; i<V; i++){
	        Deg[i]=adj[i].size();
	        if(Deg[i]%2){
	            odd_Degree++;
	        }
	    }
	    
	    if(odd_Degree!=2 and odd_Degree!=0){
	        return 0; 
	    } 
	    
	    vector<bool>visited(V,0);
	    for(int i=0; i<V; i++)
	    {
	        if(Deg[i])
	        {
	           Dfs(i,adj,visited);
	           break;
	        }
	    }
	    
	    for(int i=0; i<V; i++){
	        if(Deg[i] && !visited[i]){
	            return 0;
	        }
	    }
	    
	    if(odd_Degree==0){
	        return 2;
	    }
	    else{
	        return 1;
	    }
	   
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
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends