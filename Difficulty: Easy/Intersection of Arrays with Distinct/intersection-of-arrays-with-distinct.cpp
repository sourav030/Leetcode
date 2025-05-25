// User function template for C++

// Function to return the count of the number of elements in
// the intersection of two arrays.

class Solution {
  public:
    int numberofElementsInIntersection(vector<int> &a, vector<int> &b) {
        // Your code goes here
        unordered_set<int>st(a.begin(),a.end());
        int count=0;
        for(int i=0; i<b.size(); i++){
            if(st.find(b[i])!=st.end()){
                count++;
            }
        }
        return count;
    }
};