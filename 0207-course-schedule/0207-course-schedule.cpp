class Solution {
public:
    bool canFinish(int newCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(newCourses);
        vector<int> Indegree(newCourses,0);
        for(int i=0; i< prerequisites.size(); i++){
            graph[ prerequisites[i][0]].push_back( prerequisites[i][1]);
            Indegree[ prerequisites[i][1]]++;
        }
        queue<int>q;
        for(int i=0; i<newCourses; i++){
            if(Indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int Node=q.front();
            q.pop();
            count++;
            for(int i=0; i< graph[Node].size(); i++){
                Indegree[graph[Node][i]]--;
                if(Indegree[graph[Node][i]]==0){
                    q.push(graph[Node][i]);
                }
            }
        }
        return count==newCourses;

    }
};