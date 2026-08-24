class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        partial_sum(stones.begin(), stones.end(), stones.begin());
        int scoreDiff = stones.back();
        for (int i = n - 2; i >= 1; i--) {
            scoreDiff = max(scoreDiff, stones[i] - scoreDiff);
        }
        return scoreDiff;
    }
};