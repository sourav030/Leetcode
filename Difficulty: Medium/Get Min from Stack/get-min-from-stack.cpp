//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle=INT_MAX;
    stack<int> st;
    stack<int>minSt;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(minSt.empty()){
               return -1;
           }
           return minSt.top();
           //Write your code here
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(st.empty()){
               return -1;
           }
           int x=st.top();
           st.pop();
           minSt.pop();
           return x;
           //Write your code here
       }
       
       int peek(){
           if(st.empty()) return -1;
           return st.top();
       }
       /*push element x into the stack*/
       void push(int x){
           st.push(x);
            
        if (minSt.empty() || x <= minSt.top()) {
            minSt.push(x); // Store the new minimum
        } else {
            minSt.push(minSt.top()); // Push the previous min again
        }
           //Write your code here
       }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends