class Solution {
public:
    vector<int>row={0,0,-1,1};
    vector<int>col={1,-1,0,0};
    int n,m;
    bool solve(vector<vector<char>>&board, int idx, string &word, int r, int c){
        if(idx>=word.length()){
            return true;
        }
        char ch=board[r][c];
        board[r][c]='#';
        for(int i=0; i<4; i++){
            int nr=r+row[i];
            int nc=c+col[i];
            if(nr>=0 and nr<n and nc>=0 and nc<m){
                if(board[nr][nc]==word[idx]){
                    if(solve(board,idx+1,word,nr,nc)){
                        return true;
                    }
                }
            }
        }
        board[r][c]=ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0]){
                    if(solve(board,1,word,i,j)){
                        return true;
                    }
                }
            }
        }
        return false;

    }
};