class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        pq.push(dep[0]);
        int ans = 1;

        for(int i = 1; i < arr.size(); i++) {

           
            if(!pq.empty() && pq.top() < arr[i]) {
                pq.pop();
            }

          
            pq.push(dep[i]);

            ans = max(ans, (int)pq.size());
        }

        return ans;
    }
};
