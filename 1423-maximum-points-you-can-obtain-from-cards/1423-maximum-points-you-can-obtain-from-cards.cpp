class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l=0;
        int n=cardPoints.size();
        int windowsize=n-k;
        int r=windowsize;
        int minsum=0;
        int totalSum=0;
        int ans;

        for(int i=0; i<n;i++){
            totalSum+=cardPoints[i];
        }

        int sum=0;
        for(int i=0; i<windowsize;i++){
            sum+=cardPoints[i];
        }
        minsum=sum;

        while(r<n){
            sum-=cardPoints[l];
            l++;
            sum+=cardPoints[r];
            r++;
            minsum=min(minsum, sum);
        }
        ans=totalSum-minsum;  
        return ans;
    }
};