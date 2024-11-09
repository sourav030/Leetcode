//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
int r, c;
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
bool valid(int i,int j){
    return 0<=i and i<r and 0<=j and j< c;
}
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
         r=hospital.size();
         c=hospital[0].size();
        queue<pair<int,int>>q;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(hospital[i][j]==2){
                    q.push(make_pair(i,j));
                }
            }
        }
        
        int time=0;
        while(!q.empty()){
            
            int n=q.size();
            time++;
            while(n--){
                 int new_r=q.front().first;
                 int new_c=q.front().second;
                 q.pop();
                for(int i=0; i<4; i++){
                    if(valid(new_r+row[i],new_c+col[i]) and hospital[new_r+row[i]][new_c+col[i]]==1){
                        hospital[new_r+row[i]][new_c+col[i]]=2;
                        q.push(make_pair(new_r+row[i], new_c+col[i]));
                    }
                }
            }
        }
        
         for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(hospital[i][j]==1){
                   return -1;
                }
            }
        }
        return time==0? 0: time-1;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends