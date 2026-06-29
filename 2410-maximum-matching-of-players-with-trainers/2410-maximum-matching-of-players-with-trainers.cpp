class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i = 0, j = 0, ans = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        while (i < players.size() && j < trainers.size()) {
            if (trainers[j] >= players[i]) {
                i++;
                j++;
                ans++;
            } else {
                j++;
            }
        }
        return ans;
    }
};