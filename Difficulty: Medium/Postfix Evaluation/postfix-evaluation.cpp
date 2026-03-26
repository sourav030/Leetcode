#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int floorDiv(int a, int b) {
        if (a * b < 0 && a % b != 0)
            return (a / b) - 1;
        return a / b;
    }
  
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {
            string token = arr[i];

            if (token != "+" && token != "-" && token != "*" &&
                token != "/" && token != "^") {
                st.push(stoi(token));
            }
            else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(floorDiv(a, b));
                else if (token == "^") {
                    int res = 1;
                    for (int i = 0; i < b; i++) res *= a;
                    st.push(res);
                }
            }
        }
        return st.top();
    }
};