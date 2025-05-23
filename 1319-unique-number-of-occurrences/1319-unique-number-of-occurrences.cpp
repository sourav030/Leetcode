class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        unordered_map<int,int>mp2;
        for(auto ele:mp){
            if(mp2.find(ele.second)!=mp.end()){
                return false;
            }
            mp2[ele.second]=1;
        }
        return true;
    }
};