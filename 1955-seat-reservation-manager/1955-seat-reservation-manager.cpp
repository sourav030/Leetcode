class SeatManager {
public:
    int nextAvailability;
    priority_queue<int, vector<int>, greater<int>> pq;

    SeatManager(int n) {
        nextAvailability=1;
    }
    
    int reserve() {
        if(!pq.empty()){
            int ele=pq.top();
            pq.pop();
            return ele;
        }
        int ans=nextAvailability;
        nextAvailability++;
        return ans;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */