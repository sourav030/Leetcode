class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        int n = tickets.size();
        for(int i=0;i<n;i++)
        q.push(i);

        int Time = 0;

        while(tickets[k]!=0)
        {
            tickets[q.front()]--;
            // Kya line mein lagega
            if(tickets[q.front()])
            q.push(q.front());
            q.pop();
            Time++;
        }

        return Time;
    }
};