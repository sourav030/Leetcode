class Solution {
public:
    int n,m;
    vector<int> rows={0,0,-1,1};
    vector<int> cols={1,-1,0,0};
    bool isValid(vector<vector<char>>& board, string word,int idx, int row, int col){
        if(idx>=word.length()) return true;
        if(row<0 or row>=n or col<0 or col>=m){
            return false;
        }
        if(board[row][col]!=word[idx]){
            return false;
        }
        char tem=board[row][col];
        board[row][col]='&';
        for(int i=0; i<4; i++){
            int newRow=row+rows[i];
            int newCol=col+cols[i];
            if(isValid(board,word,idx+1,newRow,newCol)){
                return true;
            }
        }
        board[row][col]=tem;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0] and isValid(board,word,0,i,j)){
                    return true;
                }
            }
        }

        return false;
    }
};