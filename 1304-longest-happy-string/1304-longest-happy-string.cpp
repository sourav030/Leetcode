class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans = "";

        while (!pq.empty()) {
            auto [count, currChar] = pq.top();
            pq.pop();

            int n = ans.size();
            // If last two chars are same as current, use the next best
            if (n >= 2 && ans[n-1] == currChar && ans[n-2] == currChar) {
                if (pq.empty()) break;

                auto [nextCount, nextChar] = pq.top();
                pq.pop();

                ans += nextChar;
                nextCount--;
                if (nextCount > 0) pq.push({nextCount, nextChar});
                
                // Push current character back
                pq.push({count, currChar});
            } else {
                // Safe to add current character
                ans += currChar;
                count--;
                if (count > 0) pq.push({count, currChar});
            }
        }

        return ans;
    }
};
