//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    void merge(vector<int>&arr, int l, int r, int mid){
        int n1=mid-l+1;
        int n2=r-mid;
        vector<int>left(n1);
        vector<int>right(n2);
        
        
        for(int i=0; i<n1; i++){
            left[i]=arr[i+l];
        }
        
        for(int j=0; j<n2; j++){
            right[j]=arr[mid+j+1];
        }
        int k=l;
        int i=0; 
        int j=0;
        
        while(i<n1 and j<n2){
            if(left[i]<right[j]){
                arr[k]=left[i];
                i++;
            }
            else{
                arr[k]=right[j];
                j++;
            }
            k++;
        }
        
        while(i<n1){
            arr[k]=left[i];
            i++;
            k++;
        }
        
        while(j<n2){
            arr[k]=right[j];
            k++;
            j++;
        }
        
    }
    void solve(vector<int>& arr, int l, int r){
        if(l>=r) return;
        int mid=l+(r-l)/2;
        solve(arr,l,mid);
        solve(arr,mid+1,r);
        merge(arr, l, r,mid);
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        solve(arr,l,r);
    
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends