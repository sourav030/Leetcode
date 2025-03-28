//{ Driver Code Starts
// Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
public:
    int rotationCount(long long R, long long D)
    {
        // code here
       int ans=0;
       while(R and D){
           int a=R%10;
           int b=D%10;
           ans+=min(abs(a-b),10-abs(a-b));
           D=D/10;
           R=R/10;
       }
       return ans;
       
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long R, D;
        cin>>R>>D;
        
        Solution ob;
        cout<<ob.rotationCount(R, D)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends