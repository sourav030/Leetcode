class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>arr(26,0);
        for(int i=0; i<s.length(); i++){
            arr[s[i]-'a']=i;
        }
        vector<int>ans;
        int start=0;
        int end=0;
        for(int i=0; i<s.length(); i++){
            end=max(end,arr[s[i]-'a']);
            if(i==end){
                ans.push_back(end-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};