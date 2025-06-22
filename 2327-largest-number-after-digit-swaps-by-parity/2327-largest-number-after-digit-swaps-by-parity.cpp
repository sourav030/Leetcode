class Solution {
public:
    int largestInteger(int num) {
        string str=to_string(num);
        for(int i=0; i<str.length(); i++){
            int n=str[i];
            bool even=n%2==0?1:0;
            if(even){
                int largest=-1;
                for(int j=i+1; j<str.length(); j++){
                    int a=str[j];
                    bool even1=a%2==0?1:0;
                    if(even1 and a>n){
                        n=a;
                        largest=j;
                    }
                }
                if(largest!=-1){
                    swap(str[i],str[largest]);
                }
            }
            else{
                int largest=-1;
                for(int j=i+1; j<str.length(); j++){
                    int a=str[j];
                    bool even1=a%2==0?1:0;
                    if(!even1 and a>n){
                        n=a;
                        largest=j;
                    }
                }
                if(largest!=-1){
                    swap(str[i],str[largest]);
                }
            }
        }
        int n=stoi(str);
        return n;
    }
};