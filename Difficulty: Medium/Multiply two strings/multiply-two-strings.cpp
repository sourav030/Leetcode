//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are required to complete below function */
   string multiplyStrings(string& s1, string& s2) {
    int sign = 1;
    if (s1[0] == '-') {
        sign *= -1;
        s1 = s1.substr(1);
    }
    if (s2[0] == '-') {
        sign *= -1;
        s2 = s2.substr(1);
    }
    
    while (s1.size() > 1 && s1[0] == '0') s1.erase(s1.begin());
    while (s2.size() > 1 && s2[0] == '0') s2.erase(s2.begin());
    
    int n = s1.size(), m = s2.size();
    vector<int> result(n + m, 0);
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (s1[i] - '0') * (s2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    
    string res = "";
    int i = 0;
    while (i < result.size() && result[i] == 0) i++;
    for (; i < result.size(); i++) res.push_back(result[i] + '0');
    
    if (res.empty()) return "0";
    if (sign == -1) res = "-" + res;
    return res;
}
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends