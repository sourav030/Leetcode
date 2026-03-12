class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        vector<int>ans;
        for(int i=1; i<security.size(); i++){
            if(security[i]<=security[i-1]){
                prefix[i]=prefix[i-1]+1;
            }
        }

        for(int i=security.size()-2; i>=0; i--){
            if(security[i]<=security[i+1]){
                suffix[i]=suffix[i+1]+1;
            }
        }
        for(int i=time; i<n-time; i++){
            if(prefix[i]>=time and suffix[i]>=time){
                ans.push_back(i);
            }
        }
        return ans;

    }
};