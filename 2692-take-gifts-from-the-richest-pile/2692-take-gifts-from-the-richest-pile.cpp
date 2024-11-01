class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> p;
        for(auto gift:gifts){
            p.push(gift);
        }

        for(int i=0; i< k; i++){
            int first=p.top();
            p.pop();
            int remain=floor(sqrt(first));
            p.push(remain);
        }

        long long sum=0;
        while(!p.empty()){
            sum+=p.top();
            p.pop();
        }
        return sum;
    }
};