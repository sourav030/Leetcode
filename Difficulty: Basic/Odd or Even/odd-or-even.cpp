class Solution {
  public:
    bool isEven(int n) {
        // code here
        if(n&1){
            return false;
        }
        else{
            return true;
        }
        
    }
};