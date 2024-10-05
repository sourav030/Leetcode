//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    void fun(int n, string a,vector<string> &ans, int countA,int countB){
        if(a.size()==n){
            ans.push_back(a);
            return;
        }
        
        a.push_back('1');
        
        fun(n,a,ans,countA+1,countB);
        a.pop_back();
        
        if(countA>countB)
        {
            a.push_back('0');
            fun(n,a,ans,countA,countB+1);
            a.pop_back();
        }
    }
public:	
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string>ans;
	    string a;
	    int countA=0;
	    int countB=0;
	    fun(n,a ,ans, countA,countB);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends