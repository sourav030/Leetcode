class Solution {
  public:
  int sumSubstrings(string &s) {
    int sum = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n - i; len++) {
            string a = s.substr(i, len);
            sum += stoi(a);
        }
    }
    return sum;
}

};