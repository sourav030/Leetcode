//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
bool comp(const pair<int,int> &a, const pair<int,int> &b){
   double r1=(double)a.first/a.second;
   double r2=(double)b.first/b.second;
   return r1>r2;
}
class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        vector<pair<int,int>>vec;
        int n=val.size();
        for(int i=0; i<n; i++){
            vec.push_back(make_pair(val[i],wt[i]));
        }
        sort(vec.begin(),vec.end(),comp);
        
        double Profit=0;
        int i=0;
        while(capacity and i<vec.size())
        {
            if(capacity>=vec[i].second){
                Profit+=vec[i].first;
                capacity=capacity-vec[i].second;
            }
            else{
                double perWeight=(double)vec[i].first/vec[i].second;
                Profit=Profit+(perWeight*capacity);
                capacity=0;
            }
            i++;
        }
        return Profit;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends