class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> resultStack;
        string res = "";
        int i = 0;

        while (i < s.length()) {
            if (isdigit(s[i])) {
                int count = 0;
              
                while (isdigit(s[i])) {
                    count = 10 * count + (s[i] - '0');
                    i++;
                }
                counts.push(count);
            } 
            else if (s[i] == '[') {
             
                resultStack.push(res);
                res = "";
                i++;
            } 
            else if (s[i] == ']') {
             
                string temp = res;
                res = resultStack.top();
                resultStack.pop();
                
                int repeatTimes = counts.top();
                counts.pop();
                
            
                while (repeatTimes--) {
                    res += temp;
                }
                i++;
            } 
            else {
             
                res += s[i];
                i++;
            }
        }
        return res;
    }
};