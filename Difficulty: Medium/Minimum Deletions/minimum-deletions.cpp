class Solution {
  public:
  int minDelRecur(int i, int j, string &s, vector<vector<int>> &memo) {
    
    // Base Case:
    if (i >= j) return 0;
    
    // If already calculated
    if (memo[i][j] != -1) return memo[i][j];
    
    // If s[i] is equal to s[j]
    if (s[i] == s[j]) {
        memo[i][j] = minDelRecur(i+1, j-1, s, memo);
    } else {
        
        // Else we have to delete either of s[i] or s[j]
        memo[i][j] = 1 + min(minDelRecur(i+1, j, s, memo), 
        minDelRecur(i, j-1, s, memo));
    }
    
    return memo[i][j];
}
    int minDeletions(string s) {
        // code here
           int n = s.length();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return minDelRecur(0, n-1, s, memo);
    }
};