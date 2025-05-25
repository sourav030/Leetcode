class Solution {
public:
    string reverseParentheses(string s) {
         while (true) {
        int closePos = s.find(')');
        if (closePos == string::npos) break; 

      
        int openPos = closePos;
        while (s[openPos] != '(') {
            openPos--;
        }

       
        reverse(s.begin() + openPos + 1, s.begin() + closePos);

       
        s.erase(closePos, 1);   
        s.erase(openPos, 1);    
    }
    return s;
    }
};