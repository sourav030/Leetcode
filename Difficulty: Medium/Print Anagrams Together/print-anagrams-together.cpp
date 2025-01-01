//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   vector<vector<string>> anagrams(vector<string>& arr) {
    vector<vector<string>> ans;
    vector<bool> processed(arr.size(), false);  // Processed ko track karein

    for (int i = 0; i < arr.size(); i++) {
        if (processed[i]) continue;  // Agar pehle hi process ho gaya, skip karein

        string a = arr[i];
        sort(a.begin(), a.end());
        vector<string> vec;
        vec.push_back(arr[i]);  // Current string ko add karein

        for (int j = i + 1; j < arr.size(); j++) {
            if (processed[j]) continue;  // Agar pehle hi process ho gaya, skip karein

            string a2 = arr[j];
            sort(a2.begin(), a2.end());
            if (a2 == a) {  // Anagram match
                vec.push_back(arr[j]);
                processed[j] = true;  // Mark as processed
            }
        }

        ans.push_back(vec);  // Only push if we find anagrams
    }

    return ans;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends