class Solution {
public:
    int titleToNumber(string columnTitle) {
    int ans = 0;
    int n = columnTitle.length();
    
    
    for (int i = 0; i < n; i++) {
        char a = columnTitle[i];
        
      
        int index = a - 'A' + 1;
        
      
        ans = ans * 26 + index;
    }
    
    return ans;
}

};