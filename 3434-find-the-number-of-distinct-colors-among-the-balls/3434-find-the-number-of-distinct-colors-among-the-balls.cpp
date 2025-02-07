class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        unordered_map<int,int> ball;
        unordered_map<int,int> color;
        vector<int>ans;

        for(auto q: queries){
            int bal=q[0];
            int col=q[1];
            if(ball.count(bal)){
                int oldColor=ball[bal];
                color[oldColor]--;
                if(color[oldColor]==0){
                    color.erase(oldColor);
                }
            }

            ball[bal]=col;
            color[col]++;

            ans.push_back(color.size());
        }
        return ans;
    }
};