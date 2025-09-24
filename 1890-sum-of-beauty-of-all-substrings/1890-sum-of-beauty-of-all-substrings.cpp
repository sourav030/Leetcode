class Solution {
public:
    int solve(vector<int>arr){
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==0) continue;
            mini=min(mini,arr[i]);
            maxi=max(maxi,arr[i]);
        }
        return maxi-mini;
    }
    int beautySum(string s) {
        int sum=0;
        for(int i=0; i<s.length(); i++){
            vector<int>arr(26,0);
            for(int j=i; j<s.length(); j++){
                arr[s[j]-'a']++;
                sum+=solve(arr);
            }
        }
        return sum;
    }
};