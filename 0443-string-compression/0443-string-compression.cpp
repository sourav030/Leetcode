class Solution {
public:
    int compress(vector<char>& chars) {
        int index=0;
        int i=0; 
        while(i<chars.size()){
            char current=chars[i];
            int count=1;
            i++;
            while(i<chars.size() and chars[i]==current){
                i++;
                count++;
            }
            chars[index++]=current;
            if(count>1){
                string str=to_string(count);
                for(auto ele:str){
                    chars[index++]=ele;
                }
            }
        }
        return index;
    }
};