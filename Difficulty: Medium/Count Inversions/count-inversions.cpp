//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to count inversions in the array.
    int countMerge(vector<int>&arr, int start, int end, int mid){
        int n1=mid-start+1;
        int n2=end-mid;
        vector<int>left(n1);
        vector<int>right(n2);
        
        for(int i=0; i<n1; i++) 
        left[i]=arr[start+i];
        
        for(int i=0; i<n2; i++)
        right[i]=arr[mid+i+1];
        int res=0;
        int i=0; int j=0; int k=start;
        while(i<n1 and j<n2){
            if(left[i]<=right[j]){
                arr[k++]=left[i++];
            }
            else{
                res+=n1-i;
                arr[k++]=right[j++];
            }
        }
        
        while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
        
        return res;
    }
    int merge(vector<int>&arr, int start, int end){
        int res=0;
        if(start<end){
            int mid=start+(end-start)/2;
            res+=merge(arr,start,mid);
            res+=merge(arr,mid+1,end);
            res+=countMerge(arr, start,end, mid);
        }
        return res;
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int start=0;
        int end=arr.size()-1;
        return merge(arr,start, end);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends