class Solution {
public:
    bool checkValidString(string s) {
        int minCount=0;
        int maxCount=0;
        for(auto ch:s){
            if(ch=='('){
                minCount++;
                maxCount++;
            }
            else if (ch==')'){
                minCount--;
                maxCount--;
            }
            else{
                minCount--;
                maxCount++;
            }
            if(minCount<0) minCount=0;
            if (maxCount < 0) return false;
           
        }
        return minCount==0;
    }
};