class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        int end=heights[0];
        for(int i=1; i<heights.size(); i++){
            int dif=heights[i]-end;
            end=heights[i];
            if(dif>0){
                bricks=bricks-dif;
                pq.push(dif);
                if(bricks<0){
                   
                    if(ladders>0){
                         bricks+=pq.top();
                         pq.pop();
                        ladders--;
                    }
                    else{
                        return i-1;
                    }
                }
            }
        }
        return heights.size()-1;
    }
};