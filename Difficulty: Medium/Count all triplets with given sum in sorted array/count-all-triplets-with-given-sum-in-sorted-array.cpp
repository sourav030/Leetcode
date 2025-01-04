//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int ans=0, n=arr.size();
        
        for(int i=0; i<n-2; i++){
            int left=i+1, right=n-1;
            while(left<right){
                int sum=arr[i]+arr[left]+arr[right];
                if(sum<target) left++;
                else if(sum>target) right--;
                else{
                    int x=arr[left], y=arr[right];
                    int count1=0, count2=0;
                    while(left<=right and arr[left]==x){
                        left++;
                        count1++;
                    }
                    while(left<=right and arr[right]==y){
                        right--;
                        count2++;
                    }
                    if(x==y) ans+=(count1*(count1-1))/2;
                    else
                    ans+=count1*count2;
                }
            }
        }
        return ans;
    }
};   

 

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends