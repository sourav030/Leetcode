class Solution {
public:
    bool isCapital(string word){
        for(int i=0; i<word.length(); i++){
            if(word[i]<'A' or word[i]>'Z') return false;
        }
        return true;
    }
      bool isSmall(string word){
        for(int i=0; i<word.length(); i++){
            if(word[i]<'a' or word[i]>'z') return false;
        }
        return true;
    }
    bool detectCapitalUse(string word) {
         return isCapital(word) || isSmall(word) || isSmall(word.substr(1));
       
    }
};