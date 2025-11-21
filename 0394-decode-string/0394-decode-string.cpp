class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string curr = "";
        int num = 0;

        for (char c : s) {

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            else if (c == '[') {
                countStack.push(num);
                stringStack.push(curr);
                num = 0;
                curr = "";
            }

            else if (c == ']') {
                int repeat = countStack.top(); countStack.pop();
                string temp = stringStack.top(); stringStack.pop();

                while (repeat--) temp += curr;
                curr = temp;
            }

            else {
                curr += c;
            }
        }

        return curr;
    }
};
