#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int precedence(string op) {
        if (op == "+" || op == "-") return 1;
        if (op == "*" || op == "/") return 2;
        if (op == "^") return 3;
        return 0;
    }
    
    int apply(int a, int b, string op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") {
          
            if (a * b < 0 && a % b != 0)
                return (a / b) - 1;
            return a / b;
        }
        if (op == "^") return pow(a, b);
        return 0;
    }

    int evaluateInfix(vector<string>& arr) {
        stack<int> values;
        stack<string> ops;

        for (int i = 0; i < arr.size(); i++) {
            string token = arr[i];

        
            if (token != "+" && token != "-" && token != "*" &&
                token != "/" && token != "^") {
                values.push(stoi(token));
            }
            else {
                
                while (!ops.empty() &&
                       (precedence(ops.top()) > precedence(token) ||
                       (precedence(ops.top()) == precedence(token) && token != "^"))) {

                    int b = values.top(); values.pop();
                    int a = values.top(); values.pop();
                    string op = ops.top(); ops.pop();

                    values.push(apply(a, b, op));
                }

                ops.push(token);
            }
        }

      
        while (!ops.empty()) {
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            string op = ops.top(); ops.pop();

            values.push(apply(a, b, op));
        }

        return values.top();
    }
};