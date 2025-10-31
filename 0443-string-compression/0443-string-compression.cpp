class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;  // write pointer
        for (int i = 0; i < chars.size(); i++) {
            char ch = chars[i];
            int count = 0;

           
            while (i < chars.size() && chars[i] == ch) {
                i++;
                count++;
            }

     
            chars[index++] = ch;

           
            if (count > 1) {
                string str = to_string(count);
                for (char c : str)
                    chars[index++] = c;
            }

            i--; 
        }
        return index;
    }
};
