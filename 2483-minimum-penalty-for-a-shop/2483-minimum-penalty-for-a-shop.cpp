class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int penalty = 0;

        for(char c : customers) {
            if(c == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int bestTime = 0;

      
        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') {
                penalty--; 
            } else {
                penalty++; 
            }
            if(penalty < minPenalty) {
                minPenalty = penalty;
                bestTime = i + 1;
            }
        }

        return bestTime;
    }
};