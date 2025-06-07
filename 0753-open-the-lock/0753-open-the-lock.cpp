class Solution {
public:
    unordered_set<string>st;
    void fill(queue<string>&q, string str){
        for(int i=0; i<4; i++){
            char ch=str[i];
            char dec=ch=='0'? '9':ch-1;
            char inc=ch=='9'? '0':ch+1;
            str[i]=dec;
            if(st.find(str)==st.end()){
                st.insert(str);
                q.push(str);
            }
            str[i]=inc;
            if(st.find(str)==st.end()){
                st.insert(str);
                q.push(str);
            }
            str[i]=ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        for(int i=0; i<deadends.size(); i++){
            st.insert(deadends[i]);
        }
        string start="0000";
        if(st.find(start)!=st.end()) return -1;
        queue<string>q;
        q.push(start);
        int level=0;
        st.insert(start); 
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==target){
                    return level;
                }
                fill(q,curr);
            }
            level++;
        }
        return -1;

    }
};