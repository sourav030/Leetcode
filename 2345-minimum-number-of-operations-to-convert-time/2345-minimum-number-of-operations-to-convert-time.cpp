class Solution {
public:
    int solve(string s, int idx1, int idx2){
        return (s[idx1]-'0')*10+(s[idx2]-'0');
    }
    int convertTime(string current, string correct) {
        int h1=solve(current,0,1);
        int h2=solve(correct,0,1);
        int m1=solve(current,3,4);
        int m2=solve(correct,3,4);
        int h=h2-h1;
        if(h<0){
            h=24+h;
        }
        int m=m2-m1;
        if(m<0){
            m=60+m;
            h--;
        }
        int count=h;
        while(m>=15){
            m-=15;
            count++;
        }
        while(m>=5){
            m-=5;
            count++;
        }
        while(m>=1){
            m-=1;
            count++;
        }
        return count;
    }
};