class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int start1=0;
        int start2=0;
        int end1=players.size();
        int end2=trainers.size();
        int count=0;
        while(start1<end1 and start2<end2){
            
            if(players[start1]<=trainers[start2]){
                count++;
                start1++;
            }
            start2++;
        }
        return count;
    }
};