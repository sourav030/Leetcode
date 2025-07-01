class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Step 1: Sort items by price
        sort(items.begin(), items.end());

        // Step 2: Build prefix max beauty
        vector<pair<int, int>> priceBeauty;  // {price, maxBeautySoFar}
        int maxBeauty = 0;

        for (auto& item : items) {
            int price = item[0];
            int beauty = item[1];
            maxBeauty = max(maxBeauty, beauty);
            priceBeauty.push_back({price, maxBeauty});
        }

        // Step 3: Answer each query using binary search
        vector<int> ans;
        for (int q : queries) {
            int left = 0, right = priceBeauty.size() - 1;
            int res = 0;

            while (left <= right) {
                int mid = (left + right) / 2;
                if (priceBeauty[mid].first <= q) {
                    res = priceBeauty[mid].second;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            ans.push_back(res);
        }

        return ans;
    }
};
