class Solution {
public:
    bool hascommon(string temp,string ar){
        vector<int>check(26,0);
        for(auto ch:temp){
            int x=ch-'a';
            if(check[x]){
                return true;
            }
            check[x]++;
        }

        for(auto ch:ar){
             int x=ch-'a';
            if(check[x]){
                return true;
            }
            check[x]++;
        }
        return false;
    }
    int solve(int index,int n,string temp,vector<string>& arr){
        if(index>=arr.size()){
            return temp.size();
        }
        int include=0;
        int exclude=0;
        if(hascommon(temp,arr[index])){
            exclude= solve(index+1,n,temp,arr);
        }
        else{
             exclude= solve(index+1,n,temp,arr);
             include=solve(index+1,n,temp+arr[index],arr);
        }

        return max(exclude,include);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        string temp="";
        return solve(0,n,temp,arr);
    }
};