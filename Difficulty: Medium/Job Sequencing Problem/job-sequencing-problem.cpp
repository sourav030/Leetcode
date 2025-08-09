class Solution {
  public:
   vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    int n = deadline.size();
    vector<pair<int,int>> jobs;
    
    for (int i = 0; i < n; i++) {
        jobs.push_back({profit[i], deadline[i]});
    }

    // Sort by profit in descending order
    sort(jobs.begin(), jobs.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        return a.first > b.first;
    });

    // Find max deadline
    int maxDeadline = 0;
    for (int d : deadline) {
        maxDeadline = max(maxDeadline, d);
    }

    // Time slots (-1 means free)
    vector<int> slot(maxDeadline + 1, -1);

    int totalProfit = 0;
    int jobCount = 0;

    // Assign jobs
    for (auto &job : jobs) {
        int profit = job.first;
        int d = job.second;

        // Try to place this job at the last possible free slot
        for (int t = d; t > 0; t--) {
            if (slot[t] == -1) {
                slot[t] = profit; // mark as filled
                totalProfit += profit;
                jobCount++;
                break;
            }
        }
    }

    return {jobCount, totalProfit};
}
};