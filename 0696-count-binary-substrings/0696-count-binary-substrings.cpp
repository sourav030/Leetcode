class Solution {
public:
    int countBinarySubstrings(string s) {
        int sum=0;
        vector<int>group;
        int count=1;
        for(int i=1; i<s.length(); i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                group.push_back(count);
                count=1;
            }
        }
        group.push_back(count);
        for(int i=0; i<group.size()-1; i++){
            sum+=min(group[i],group[i+1]);
        }
        return sum;
    }
};