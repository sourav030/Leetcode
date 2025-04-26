//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends

//Back-end complete function Template for C++
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data=val;
        left=right=nullptr;
    }
};

class Solution {
  public:
    int n;
    
    unordered_map<int,int>mp;
    Node* solve(int preorder[], int start, int end,int &index){
        
        if(index>n or start>end) return nullptr;
        int rootValue=preorder[index++];
        Node* root=new Node(rootValue);
        int mid=mp[rootValue];
        root->left=solve(preorder,start,mid-1,index);
        root->right=solve(preorder,mid+1,end,index);
        return root;
        
    }
    
    bool check(Node* root, int postorder[],int &index){
        if(!root) return true;
         bool left=check(root->left,postorder,index);
         bool right=check(root->right,postorder,index);
         if(root->data!=postorder[index]) return false;
         index++;
         return left and right;
    }
    
    bool checktree(int preorder[], int inorder[], int postorder[], int N) {
        // Your code goes here
        mp.clear();
        for(int i=0; i<N; i++){
            mp[inorder[i]]=i;
        }
        int start=0;
        int end=N-1;
         n=N-1;
         int index=0;
        Node* root=solve(preorder,start,end,index);
        index=0;
        return  check(root,postorder,index);
    }
};



//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	
cout << "~" << "\n";
} 
	return 0; 
} 


// } Driver Code Ends