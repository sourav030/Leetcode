class Solution {
public:
    vector<vector<string>>ans;
    vector<string>path;
    void solve(int index,string s){
        if(index==s.length()){
            ans.push_back(path);
            return;
        }
        for(int i=index; i<s.length(); i++){
            if(isPalindrome(index,i,s)){
                path.push_back(s.substr(index,i-index+1));
                solve(i+1,s);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(int start, int end, string s){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
     solve(0,s);
     return ans;   
    }
};