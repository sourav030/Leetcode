class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum=0;
        for(int i=0; i<k; i++){
            leftSum+=cardPoints[i];
        }
        int ans=leftSum;
        int rightSum=0;
        int n=cardPoints.size();
        for(int i=0; i<k; i++){
            rightSum+=cardPoints[n-i-1];
            leftSum-=cardPoints[k-i-1];
            ans=max(ans,leftSum+rightSum);
        }
        return ans;
    }
};