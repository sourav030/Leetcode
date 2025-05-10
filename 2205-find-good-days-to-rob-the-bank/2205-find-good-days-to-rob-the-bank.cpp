class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int>ans;
        int n=security.size();
        vector<int>prefix(n,0);
        vector<int>sufix(n,0);

        for(int i=1; i<n; i++){
            if(security[i]<=security[i-1]){
                prefix[i]=prefix[i-1]+1;
            }
        }

        for(int i=n-2; i>=0; i--){
            if(security[i]<=security[i+1]){
                sufix[i]=sufix[i+1]+1;
            }
        }

        for(int i=time; i<n-time; i++){
            if (prefix[i] >= time && sufix[i] >= time) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};