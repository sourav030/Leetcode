class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        
        // Push all non-zero amounts into max heap
        for (int a : amount) {
            if (a > 0) pq.push(a);
        }
        
        int seconds = 0;

        while (!pq.empty()) {
            int first = pq.top(); pq.pop();

            if (pq.empty()) {
                
                seconds += first;
                break;
            }

            int second = pq.top(); pq.pop();

          
            first--;
            second--;
            seconds++;

            if (first > 0) pq.push(first);
            if (second > 0) pq.push(second);
        }

        return seconds;
    }
};
