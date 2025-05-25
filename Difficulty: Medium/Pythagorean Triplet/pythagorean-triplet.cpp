class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n = arr.size();
    int maxEle = 0;
    for (int ele: arr) 
        maxEle = max(maxEle, ele);

    // Visited array to mark the elements
    vector<bool> vis(maxEle + 1, 0);

    // Marking each element of input array
    for (int ele: arr)
        vis[ele] = true;

    // Iterate for all possible a
    for (int a = 1; a < maxEle + 1; a++) {

       
        if (vis[a] == false)
            continue;

    
        for (int b = 1; b < maxEle + 1; b++) {

           
        	if (vis[b] == false)
            	continue;

            int c = sqrt(a * a + b * b);

            if ((c * c) != (a * a + b * b) || c > maxEle)
                continue;

          
            if (vis[c] == true) {
                return true;
            }
        }
    }
    return false;
    }
};