class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
   int findPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    // Min-heap to store current departure times on platforms
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(dep[0]);
    int maxPlatform = 1;

    for (int i = 1; i < arr.size(); i++) {
        // Remove all trains that have already departed
        while (!pq.empty() && arr[i] > pq.top()) {
            pq.pop();
        }

        // Assign current train to a platform (new or reused)
        pq.push(dep[i]);

        // Max platforms needed so far
        maxPlatform = max(maxPlatform, (int)pq.size());
    }

    return maxPlatform;
}

};
