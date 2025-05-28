class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int baseHappy = 0;

       
        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) {
                baseHappy += customers[i];
            }
        }

       
        int maxExtra = 0;

        for(int i = 0; i <= n - minutes; i++) {
            int extra = 0;

         
            for(int j = i; j < i + minutes; j++) {
                if(grumpy[j] == 1) {
                    extra += customers[j];
                }
            }

            maxExtra = max(maxExtra, extra);
        }

        return baseHappy + maxExtra;
    }
};
