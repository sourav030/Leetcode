class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char,int>mp;
        mp['A']=1;
        mp['E']=1;
        mp['I']=1;
        mp['O']=1;
        mp['U']=1;
        mp['a']=1;
        mp['e']=1;
        mp['i']=1;
        mp['o']=1;
        mp['u']=1;
        vector<char>arr;
        for(int i=0; i<s.length(); i++){
            if(mp.find(s[i])!=mp.end())
            arr.push_back(s[i]);
        }
        reverse(arr.begin(),arr.end());
        int i=0;
        for(int k=0; k<s.length(); k++){
            if(mp.find(s[k])!=mp.end()){
                s[k]=arr[i];
                i++;
            }
        }
        return s;
    }
};