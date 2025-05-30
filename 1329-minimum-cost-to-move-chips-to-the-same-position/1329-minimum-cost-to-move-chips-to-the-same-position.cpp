class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int cost=0;
        int cost1=0;
        int n=position.size();
        for(int i=0; i<n; i++){
            if(position[i]%2!=0){
                cost++;
            }
            if(position[i]%2==0){
                cost1++;
            }
          
        }
        return min(cost,cost1);
    }
};