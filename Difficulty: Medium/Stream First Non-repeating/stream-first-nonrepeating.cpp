class Solution {
  public:
    string FirstNonRepeating(string &s) {
        // Code here
        queue<char>q;
        string ans;
        unordered_map<char, int>mp;
        for(int i=0; i<s.length(); i++){
            if(mp.find(s[i])==mp.end()){
                q.push(s[i]);
            }
            mp[s[i]]++;
            while(!q.empty() and mp[q.front()]>1){
                q.pop();
            }
            if(!q.empty()){
                ans+=q.front();
            }
            else{
                ans+='#';
            }
        }
        return ans;
    }
};