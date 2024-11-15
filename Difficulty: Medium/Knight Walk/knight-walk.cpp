//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int row[8]={2,2,-2,-2,1,-1,1,-1};
    int col[8]={1,-1,1,-1,2,2,-2,-2};
    
    bool valid(int i, int j, int n){
      if(i>=0 and i<n and j>=0 and j<n){
          return 1;
      }
      return 0;                  
    }
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    KnightPos[0]--; 
	    KnightPos[1]--;
	    TargetPos[0]--;
	    TargetPos[1]--;
	    if(KnightPos[0]==TargetPos[0] and KnightPos[1]==TargetPos[1]){
	         return 0;
	    }
	    queue<pair<int,int>>q;
	    vector<vector<bool>>chess(N,vector<bool>(N,0));
	    q.push({KnightPos[0],KnightPos[1]});
	    chess[KnightPos[0]][KnightPos[1]]=1;
	    
	    int step=0;
	    
	    while(!q.empty()){
	        int count=q.size();
	        while(count--){
	            int i=q.front().first;
	            int j=q.front().second;
	            q.pop();
	            
	            
	            for(int k=0; k<8; k++){
	                int new_i=i+row[k];
	                int new_j=j+col[k];
	                
	                
	                if(valid(new_i, new_j, N) and !chess[new_i][new_j]){
	                    if(new_i==TargetPos[0] and new_j==TargetPos[1]){
	                        return step+1;
	                    }
	                    chess[new_i][new_j]=1;
	                    q.push({new_i, new_j});
	                }
	            }
	            
	        }
	        step++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends