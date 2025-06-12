class Solution {
public:
    vector<int> printKClosest(vector<int>& arr, int k, int x) {
        // Min-heap: closest elements come first
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int val : arr) {
            if (val == x) continue;

            int diff = abs(val - x);
            pq.push({diff, -val});
        }

        vector<int> result;
        while (k-- && !pq.empty()) {
            result.push_back(-pq.top().second); 
            pq.pop();
        }

        return result;
    }
};
