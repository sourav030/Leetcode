class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto ele:stones){
            pq.push(ele);
        }
        while(!pq.empty()){
            int a=pq.top();
            pq.pop();
            if(pq.empty()){
                return a;
            }
            int b=pq.top();
            pq.pop();
            if(a-b!=0){
                pq.push(a-b);
            }
        }
        return 0;
    }
};