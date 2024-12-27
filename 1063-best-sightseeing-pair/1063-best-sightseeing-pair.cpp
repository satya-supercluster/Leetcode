class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int bestLeft = values[0];
        for (int j = 1; j < values.size(); j++) {
            maxScore = max(maxScore, bestLeft + values[j] - j);
            bestLeft = max(bestLeft, values[j] + j);
        }
        return maxScore;
    }
};