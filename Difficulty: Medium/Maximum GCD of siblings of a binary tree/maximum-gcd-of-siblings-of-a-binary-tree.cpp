//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
  public:
    int gcd(int a, int b){
        int c=min(a,b);
        while(c>1){
            if(a%c==0 and b%c==0){
                break;
            }
            c--;
        }
        return c;
    }
    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        // code here
        unordered_map<int,vector<int>>mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i][0]].push_back(arr[i][1]);
        }
        
        int maxi=0;
        for(auto v:mp){
            if(v.second.size()>=2){
            int first=v.second[0];
            int second=v.second[1];
            int ans=gcd(first,second);
            maxi=max(maxi,ans);
            }
        }
        return maxi==INT_MAX? 0: maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends