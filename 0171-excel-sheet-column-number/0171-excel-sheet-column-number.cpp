class Solution {
public:
    // int titleToNumber(string columnTitle) {
    //     vector<int>Alphabet;
    //     for(int i=0; i<=26; i++){
    //         Alphabet.push_back(i);
    //     }
    //     int ans=0;
    //     int n=columnTitle.size();
    //     int x=n;
    //     for(int i=0; i<n; i++){
    //         char a=columnTitle[i];
    //         int index=a-'A';
    //         index=index+1;
    //         if(x>1){
    //             ans+=Alphabet[index]*26;
    //             x--;
    //         }
    //         else
    //         {
    //             ans+=Alphabet[index];
    //         }
    //     }
    //     return ans;
    // }
    int titleToNumber(string columnTitle) {
        int sum = 0;
        for(int i=0; i<columnTitle.length(); i++){
            sum = sum * 26 + (columnTitle[i] - 'A' + 1);
        }
        return sum;
    }
};