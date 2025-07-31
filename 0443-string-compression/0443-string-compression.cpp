class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;  
        int i = 0;      
        while (i < chars.size()) {
            char current = chars[i];
            int count = 0;

            
            while (i < chars.size() && chars[i] == current) {
                i++;
                count++;
            }

            chars[index++] = current;

            
            if (count > 1) {
                string cnt = to_string(count);
                for (char ch : cnt) {
                    chars[index++] = ch;
                }
            }
        }

        return index;
    }
};
