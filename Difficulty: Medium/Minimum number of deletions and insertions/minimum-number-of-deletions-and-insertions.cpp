//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
    int find(int n, int m, string &str1, string &str2,vector<vector<int>> &dp){
        if(n==0 or m==0){
            return 0;
        }
        if(dp[n][m]!=-1) return dp[n][m];
        if(str1[n-1]==str2[m-1]){
            return dp[n][m]= 1+find(n-1,m-1,str1,str2,dp);
        }
        else {
            return dp[n][m]= max(find(n-1,m,str1,str2,dp),find(n,m-1,str1,str2,dp));
        }
    }
	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,-1));
	    int x=find(str1.size(),str2.size(),str1,str2,dp);
	    
	    return (str1.size()-x)+(str2.size()-x);
	    
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends