//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> computeLPS(const string& pat) {
        vector<int> lps(pat.size(), 0);
        int len = 0;
        int i = 1;

        while (i < pat.size()) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    vector<int> search(string& pat, string& txt) {
        for (char &ch : pat) ch = tolower(ch);
        for (char &ch : txt) ch = tolower(ch);

        vector<int> ans;
        vector<int> lps = computeLPS(pat);

        int i = 0, j = 0;

        while (i < txt.size()) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == pat.size()) {
                ans.push_back(i - j);
                j = lps[j - 1];
            }
            else if (i < txt.size() && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        cout << "[";
        for (int i = 0; i < res.size(); i++) {
            cout << res[i];
            if (i != res.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}

// } Driver Code Ends