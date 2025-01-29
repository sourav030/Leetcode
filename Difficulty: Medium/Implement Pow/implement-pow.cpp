//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double solve(double b,int e){
        if(e==1){
            return (double)b;
        }
        else if(e==0){
            return 1;
        }
        if(e%2==0) return (double) solve(b,e/2)*solve(b,e/2);
        else return (double)b*solve(b,e/2)*solve(b,e/2);
    }
    double power(double b, int e) {
        // code here
        if(e<0){
            e=-e;
            b=1/b;
        }
        return solve(b,e);
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends