class Solution {
  public:
    string caseSort(string& s) {
        // code here
        string upper="";
        string lowwer="";
        for(int i=0; i<s.length();i++){
            if(s[i]>='A' and s[i]<='Z'){
                upper+=s[i];
            }
            else{
                lowwer+=s[i];
            }
        }
        sort(upper.begin(),upper.end());
        sort(lowwer.begin(),lowwer.end());
        int j=0, k=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]>='A' and s[i]<='Z'){
                s[i]=upper[j];
                j++;
            }
            else{
                s[i]=lowwer[k];
                k++;
            }
        }
        return s;
    }
};