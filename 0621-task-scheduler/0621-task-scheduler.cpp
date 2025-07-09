#define P pair<int, char>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for (char ch : tasks) {
            mp[ch]++;
        }

        priority_queue<P> pq;
        for (auto ele : mp) {
            pq.push({ele.second, ele.first});
        }

        string ans = "";

        while (!pq.empty()) {
            vector<P> temp;
            int slots = n + 1;  

            while (slots > 0 && !pq.empty()) {
                auto [count, ch] = pq.top(); pq.pop();
                ans += ch;       
                count--;
                if (count > 0) {
                    temp.push_back({count, ch}); 
                }
                slots--;
            }

          
            for (auto &p : temp) {
                pq.push(p);
            }


            if (!pq.empty() && slots > 0) {
                ans += string(slots, '_');  
            }
        }

        return ans.length();
    }
};
