//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<int> ans = {0, 0};
        
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({deadline[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (const auto &job : jobs) {
            if (job.first > pq.size())
                pq.push(job.second);
            else if (!pq.empty() && pq.top() < job.second) {
                pq.pop();
                pq.push(job.second);
            }
        }
        
        while (!pq.empty()) {
            ans[1] += pq.top();
            pq.pop();
            ans[0]++;
        }
        
        return ans;

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends