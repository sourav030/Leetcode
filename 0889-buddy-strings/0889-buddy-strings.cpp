class Solution {
public:
    bool check(string s){
        unordered_set<char>st(begin(s),end(s));
        if(st.size()==s.length()) return false;
        return true;

    }
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        if(s==goal){
            return check(s);
        }
        vector<int>arr;
        for(int i=0; i<s.length(); i++){
            if(s[i]!=goal[i]){
                arr.push_back(i);
            }
        }
        if(arr.size()!=2){
            return false;
        }
        swap(s[arr[0]],s[arr[1]]);
        return s==goal;
    }
};