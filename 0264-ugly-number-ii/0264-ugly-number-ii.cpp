class Solution {
public:
    
    int nthUglyNumber(int n) {
   priority_queue<long long, vector<long long>, greater<long long>> pq;
     pq.push(1);
     unordered_set<long long>seen;
     seen.insert(1);
     long long uggly=0;
     while(n--){
         uggly=pq.top();
        pq.pop();
        if(seen.find(uggly*2)==seen.end()){
            pq.push(uggly*2);
            seen.insert(uggly*2);
        }
        if(seen.find(uggly*3)==seen.end()){
            pq.push(uggly*3);
            seen.insert(uggly*3);
        }
        if(seen.find(uggly*5)==seen.end()){
            pq.push(uggly*5);
            seen.insert(uggly*5);
        }
    
     } return uggly;
    }
};