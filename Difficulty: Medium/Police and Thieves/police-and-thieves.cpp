class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        vector<int> police;
        vector<int> thieves;

        // Store indices of all police and thieves
        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P') police.push_back(i);
            else if (arr[i] == 'T') thieves.push_back(i);
        }

        int i = 0, j = 0, count = 0;

       
        while (i < police.size() && j < thieves.size()) {
            if (abs(police[i] - thieves[j]) <= k) {
                count++;
                i++;
                j++;
            }
            else if (thieves[j] < police[i]) {
                j++;
            }
            else {
                i++;
            }
        }

        return count;
    }
};
