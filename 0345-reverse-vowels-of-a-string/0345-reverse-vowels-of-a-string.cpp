class Solution {
public:
    unordered_map<char, int>mp;
    string reverseVowels(string s) {

    mp['a'] = 1;
    mp['e'] = 2;
    mp['i'] = 3;
    mp['o'] = 4;
    mp['u'] = 5;

    // Uppercase vowels
    mp['A'] = 6;
    mp['E'] = 7;
    mp['I'] = 8;
    mp['O'] = 9;
    mp['U'] = 10;

        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(mp.find(s[i])!=mp.end() and mp.find(s[j])!=mp.end()){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(mp.find(s[i])!=mp.end()){
                j--;
            }
            else{
                i++;
            }
        }
        return s;
    }
};