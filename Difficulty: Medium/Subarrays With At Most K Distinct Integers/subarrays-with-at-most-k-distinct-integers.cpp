//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int atMostK(vector<int> &arr, int k) {
        // code here
        int result=0;
        int left=0;
        int right=0;
        unordered_map<int,int>mp;
        while(right<arr.size()){
            mp[arr[right]]++;
            if(mp[arr[right]]==1){
                k=k-1;
            }
            while(k<0){
                mp[arr[left]]--;
                if(mp[arr[left]]==0){
                    mp.erase(arr[left]);
                    k++;
                }
                left++;
            }
            result+=right-left+1;
            right++;
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.atMostK(arr, k) << endl;
    }
    return 0;
}
// } Driver Code Ends