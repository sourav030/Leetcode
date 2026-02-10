class Solution {
  public:
  
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    string str = "DULR";

    vector<string> ans;
    int n, m;

    void solve(vector<vector<int>>& arr, int r, int c, string st) {

        if (r == n-1 && c == m-1) {
            ans.push_back(st);
            return;
        }

        arr[r][c] = 0;   

        for (int i = 0; i < 4; i++) {
            int new_r = r + dx[i];
            int new_c = c + dy[i];

            if (new_r >= 0 && new_r < n &&
                new_c >= 0 && new_c < m &&
                arr[new_r][new_c] != 0) {

                st.push_back(str[i]);
                solve(arr, new_r, new_c, st);
                st.pop_back();       
            }
        }

        arr[r][c] = 1;   
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {

        n = maze.size();
        m = maze[0].size();

        if (maze[0][0] == 0)
            return {};

        string st = "";
        solve(maze, 0, 0, st);

        sort(ans.begin(), ans.end());   
        return ans;
    }
};
