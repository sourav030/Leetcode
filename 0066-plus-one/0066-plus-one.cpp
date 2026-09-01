class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       
       vector<int>arr;
       int last=digits[digits.size()-1]+1;
       int carry=last/10;
       arr.push_back(last%10);
       for(int i=digits.size()-2; i>=0; i--){
        int num=digits[i]+carry;
        arr.push_back(num%10);
        carry=num/10;
       }
       if(carry){
        arr.push_back(carry);
       }
       reverse(arr.begin(),arr.end());
       return arr;
       
    }
};