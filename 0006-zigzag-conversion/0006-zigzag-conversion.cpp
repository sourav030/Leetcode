class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        int n = s.length();

        vector<vector<char>> arr(numRows, vector<char>(n, '\0'));

        int i = 0;      
        int row = 0;   
        int col = 0;    

        while (i < n) {
            
            for (row = 0; row < numRows && i < n; row++) {
                arr[row][col] = s[i++];
            }

            row -= 2; 
            col++;

            while (row > 0 && i < n) {
                arr[row][col] = s[i++];
                row--;
                col++;
            }
        }

        
        string res = "";
        for (int r = 0; r < numRows; r++) {
            for (int c = 0; c < n; c++) {
                if (arr[r][c] != '\0')
                    res += arr[r][c];
            }
        }

        return res;
    }
};
