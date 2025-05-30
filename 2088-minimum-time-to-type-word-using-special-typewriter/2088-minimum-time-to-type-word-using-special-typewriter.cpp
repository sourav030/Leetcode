class Solution {
public:
    int minTimeToType(string word) {
        char curr='a';
        int sum=0;
       
        for(int i=0; i<word.length(); i++){
           int dis=abs(word[i]-curr);
            dis=min(dis,26-dis);
            sum+=dis;
            curr=word[i];
        }
        sum+=word.length();
        return sum;
    }
};