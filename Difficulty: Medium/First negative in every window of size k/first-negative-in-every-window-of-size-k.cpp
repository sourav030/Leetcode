class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        queue<int>q;  // store the negative number
        vector<int>ans;
        int start=0;
        int end=0;
        while(end<arr.size()){
            if(arr[end]<0){
                q.push(arr[end]);
            }
            if(end-start+1==k){
                if(!q.empty()){
                    ans.push_back(q.front());
                    if(q.front()==arr[start]){
                        q.pop();
                    }
                }
                else{
                    ans.push_back(0);
                }
                start++;
            }
            end++;
        }
        return ans;
    }
};