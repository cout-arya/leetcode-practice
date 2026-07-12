class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        unordered_map<int, int> rank;
        sort(temp.begin(), temp.end());
        int currentRank = 1;
        for (int num : temp) {
            if (!rank.count(num)) {
                rank[num] = currentRank++;
            }
        }
        for (int& num : arr) {
            num = rank[num];
        }
        return arr;
    }
};