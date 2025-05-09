class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();

        vector<int>prefix(n+1,0);
        vector<int>suffix(n+1,0);

        for(int i=1; i<=n; i++){
            if(customers[i-1]=='N'){
                prefix[i]=prefix[i-1]+1;
            }
            else{
                prefix[i]=prefix[i-1];
            }
        }

        for(int i=n-1; i>=0; i--){
            if(customers[i]=='Y'){
                suffix[i]=suffix[i+1]+1;
            }
            else{
                suffix[i]=suffix[i+1];
            }
        }

        int minPenalty=INT_MAX;
        int minHour=INT_MAX;

        for(int i=0; i<=n; i++){
            int currentPenalty=prefix[i]+suffix[i];
            if(currentPenalty<minPenalty){
                minPenalty=currentPenalty;
                minHour=i;
            }
        }

        return minHour;
    }
};