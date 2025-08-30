class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> stringStack;
        int num = 0;
        string curr = "";

        for (auto c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                numStack.push(num);
                stringStack.push(curr);
                num = 0;
                curr = "";
            }
            else if (c == ']') {
                int repeat = numStack.top(); numStack.pop();
                string prev = stringStack.top(); stringStack.pop();
                string temp = "";
                while (repeat--) {
                    temp += curr;
                }
                curr = prev + temp;
            }
            else {
                curr += c;
            }
        }
        return curr;
    }
};
