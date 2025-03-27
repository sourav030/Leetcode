//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int,int>>vec;
        for(int i=0; i<start.size(); i++){
            vec.push_back(make_pair(finish[i],start[i]));
        }
        sort(vec.begin(),vec.end());
        int maxAcitivity=1;
        int endTime=vec[0].first;
        for(int i=1; i<start.size(); i++){
            if(vec[i].second>endTime){
                maxAcitivity++;
                endTime=vec[i].first;
            }
        }
        return maxAcitivity;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends