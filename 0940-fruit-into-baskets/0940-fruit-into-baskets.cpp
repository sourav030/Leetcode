class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int>mp;
        int start=0;
        int end=0;
        int maxLen=0;
        while(end<fruits.size()){
            mp[fruits[end]]++;
            if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[start]]--;
                    if(mp[fruits[start]]==0){
                        mp.erase(fruits[start]);
                    }
                    start++;
                }
            }
            if(mp.size()<=2){
                maxLen=max(maxLen,end-start+1);
            }
                end++;
        }
        return maxLen;
    }
};