//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int find(int n,int m,string &s,string &s2,vector<vector<int>> &dp){
        if(n<=0 or m<=0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if (n==m) return dp[n][m]= max(find(n-1,m,s,s2,dp),find(n,m-1,s,s2,dp));
        else if(s[n-1]==s2[m-1]) return dp[n][m]=1+find(n-1,m-1,s,s2,dp);
        else return dp[n][m]=max(find(n-1,m,s,s2,dp),find(n,m-1,s,s2,dp));
        
    }
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    vector<vector<int>>dp(str.size()+1,vector<int>(str.size()+1,-1));
		    return find(str.size(),str.size(),str,str,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends