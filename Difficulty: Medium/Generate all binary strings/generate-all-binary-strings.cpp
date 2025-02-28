//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:
    
    vector<string>ans;
    void solve(string &s, int num,bool flag){
        if(s.length()==num){
            ans.push_back(s);
            return;
        }
        s.push_back('0');
        solve(s,num,false);
        
        s.pop_back();
        if(!flag){
            s.push_back('1');
            solve(s,num,true);
            
            s.pop_back();
        }
        
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        bool flag=false;
        string s;
        solve(s,num,flag);
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends