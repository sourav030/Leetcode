class Solution {
  public:
    int firstElementKTime(vector<int>& arr, int k) {
        // write code
        unordered_map<int,int>mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
            if(mp[arr[i]]==k){
                return arr[i];
            }
        }
        return -1;
    }
};