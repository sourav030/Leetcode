class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int n = customers.size();
        int baseHappy = 0;

       
        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0)
                baseHappy += customers[i];
        }

     
        int maxExtra = 0, extra = 0;
        int start = 0;

        for(int end = 0; end < n; end++) {
            
            if(grumpy[end] == 1)
                extra += customers[end];

          
            if(end - start + 1 > k) {
                if(grumpy[start] == 1)
                    extra -= customers[start];
                start++;
            }

            
            maxExtra = max(maxExtra, extra);
        }

        return baseHappy + maxExtra;
    }
};
