class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        int n = tickets.size();
        for(int i=0;i<n;i++)
        q.push(i); // hum sare index ko queue main push krenge

        int Time = 0;

        while(tickets[k]!=0) // tickest[k] ki value 0 nhi hogi tabhi chelga our usee ticket denge
        {
            tickets[q.front()]--; // useko ticket dene kr badd decrement krenge
            // Kya line mein lagega
            if(tickets[q.front()]) // agar ticket[q.front ki value 0 nhi hai] use push kro qu main
            q.push(q.front());
                // abh q.front ki delete krenge our time ko increament kr denge
            q.pop();
            Time++;
        }

        return Time;
    }
};