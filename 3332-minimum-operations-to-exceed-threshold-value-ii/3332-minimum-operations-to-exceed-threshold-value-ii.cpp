class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());

        int cnt = 0;
        while (pq.size() > 1 && pq.top() < k) {
            long long first = pq.top();
            pq.pop(); 

            if (pq.empty()) break;  // Ensure there's a second element to process

            long long second = pq.top();
            pq.pop();

            long long temp = first * 2LL + second;
            pq.push(temp);
            cnt++;
        }
        return cnt;
    }
};