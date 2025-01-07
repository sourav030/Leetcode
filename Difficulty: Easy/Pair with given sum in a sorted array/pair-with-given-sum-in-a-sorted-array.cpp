//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int res = 0;
    int n = arr.size();
    int left = 0, right = n - 1;

    while (left < right) {
      
        // If sum is greater 
        if (arr[left] + arr[right] < target)
            left++;

        // If sum is lesser
        else if (arr[left] + arr[right] > target)
            right--;

        // If sum is equal
        else {
          
            int cnt1 = 0, cnt2 = 0;
            int ele1 = arr[left], ele2 = arr[right];
          
            // Count frequency of first element of the pair
            while (left <= right and arr[left] == ele1) {
                left++;
                cnt1++;
            }
          
            // Count frequency of second element of the pair
            while(left <= right and arr[right] == ele2) {
                right--;
                cnt2++;
            }
           
            // If both the elements are same, then count of
            // pairs = the number of ways to choose 2 
            // elements among cnt1 elements
            if(ele1 == ele2) 
                res += (cnt1 * (cnt1 - 1))/2;
          
            // If the elements are different, then count of
            // pairs = product of the count of both elements
            else 
                res += (cnt1 * cnt2);
        }
    }
    return res;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends