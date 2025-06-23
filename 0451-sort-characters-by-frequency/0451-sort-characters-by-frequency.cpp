class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto ele:s){
            mp[ele]++;
        }
        vector<pair<int,char>>arr;
        for(auto ele:mp){
           arr.push_back({ele.second, ele.first});
        }
     sort(arr.begin(), arr.end(), greater<>());
        
        string ans="";
       for (auto& [freq, ch] : arr) {
            ans += string(freq, ch); // Append character 'ch' freq times
        }
        return ans;
    }
};