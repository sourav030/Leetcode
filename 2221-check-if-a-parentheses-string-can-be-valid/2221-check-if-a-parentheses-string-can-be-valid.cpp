class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length()%2!=0){
            return false;
        }
        stack<int>open;
        stack<int>closed;

        for(int i=0; i<s.length(); i++){
            if(locked[i]=='0'){
                open.push(i);
            }
            else if(s[i]=='('){
                closed.push(i);
            }
            else if(s[i]==')'){
                if(!closed.empty()){
                    closed.pop();
                }
                else if(!open.empty()){
                    open.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!open.empty() and !closed.empty() and closed.top()<open.top()){
            open.pop();
            closed.pop();
        }
        return closed.empty();
    }
};