class Solution {
public:
    static bool comp(pair<int,char>a, pair<char,int>b){
        return a.first>b.first;
    }
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto ele:s){
            mp[ele]++;
        }
        vector<pair<int,char>>arr;
        for(auto ele:mp){
            arr.push_back({ele.second,ele.first});
        }
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        string result="";
        for(auto [fre,ch]:arr){
            result+=string(fre,ch);
        }
        return result;
    }
};