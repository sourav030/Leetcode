class Solution {
public:
    int compress(vector<char>& chars) {
        int index=0;
        int i=0;
        int n=chars.size();
        while(i<chars.size()){
            char curr=chars[i];
            i++;
            int count=1;
            while(i<n and curr==chars[i])
            {
                count++;
                i++;
            }
            chars[index]=curr;
            index++;
            if(count>1){
                string ans=to_string(count);
                for(char ch:ans){
                    chars[index++]=ch;
                }
            }
        }
        return index;
    }
};