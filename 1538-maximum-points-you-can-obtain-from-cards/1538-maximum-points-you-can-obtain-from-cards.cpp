class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(),0);
        int windowSize = cardPoints.size()-k;

        int miniSum = accumulate(cardPoints.begin(), cardPoints.begin()+windowSize,0);
        int currSum = miniSum;

        for(int i = windowSize; i < cardPoints.size(); ++i){
            currSum = currSum + cardPoints[i] - cardPoints[i-windowSize];
            miniSum = min(currSum,miniSum);
        }
        return totalSum-miniSum;
    }
};