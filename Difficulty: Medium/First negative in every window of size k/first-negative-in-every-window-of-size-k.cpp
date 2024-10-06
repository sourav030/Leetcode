//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends



vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
                                                 
                            vector<long long>ans;
                            queue<long long> q;
                            for(int i=0; i<k-1; i++){
                                if(A[i]<0){
                                     q.push(i);
                                }
                               
                                
                            }
                            for(int i=k-1; i<N; i++){
                                if(A[i]<0){
                                     q.push(i);
                                }
                                if(q.empty()){
                                    ans.push_back(0);
                                }
                                else{
                                    if(q.front()<=i-k){
                                        q.pop();
                                    }
                                    if(q.empty()){
                                        ans.push_back(0);
                                    }
                                    else {
                                        ans.push_back(A[q.front()]);
                                    }
                                }
                            }
                            return ans;
                                                 
 }