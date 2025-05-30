class Solution {
  public:
    bool checkKthBit(int n, int k) {
        // Your code here
        int val=(1<<k);
        if((n & val)==0){
            return 0;
        }
        else{
            return 1;
        }
    }
};