class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>arr(26,0);
        for(auto ele:sentence){
            arr[ele-'a']=1;
        }
        for(int i=0; i<26; i++){
            if(arr[i]==0){
                return false;
            }
        }
        return true;
    }
};