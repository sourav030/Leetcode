class Solution {
public:
    int bestClosingTime(string customers) {
        int totalY=0;
        for(int i=0; i<customers.size(); i++){
            if(customers[i]=='Y') totalY++;
        }

        int countN=0;
        int countY=0;
        int miniP=INT_MAX;
        int miniH=INT_MAX;

        for(int i=0; i<=customers.size(); i++){
            int currentY=totalY-countY;
            int currentP=currentY+countN;
            if(currentP<miniP){
                miniP=currentP;
                miniH=i;
            }
            if (i < customers.size()) {
                if (customers[i] == 'Y') countY++;
                else countN++;
            }
        }
       
        return miniH;
    }
};