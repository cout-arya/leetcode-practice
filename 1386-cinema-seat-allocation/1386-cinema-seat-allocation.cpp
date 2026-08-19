class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        int ans = 2 * n;
        sort(reservedSeats.begin(), reservedSeats.end());
        for (int i = 0; i < m; i++) {
            int curr = reservedSeats[i][0];
            int f1 = 1;
            int f2 = 1;
            int f3 = 1;
            while (i < m && reservedSeats[i][0] == curr) {
                if (reservedSeats[i][1] >= 2 && reservedSeats[i][1] <= 5) {
                    f1 = 0;
                    if (reservedSeats[i][1] >= 4 && reservedSeats[i][1] <= 5) {
                        f2 = 0;
                    }
                } else if (reservedSeats[i][1] >= 6 &&
                           reservedSeats[i][1] <= 9) {
                    f3 = 0;
                    if (reservedSeats[i][1] >= 6 && reservedSeats[i][1] <= 7) {
                        f2 = 0;
                    }
                }
                i++;
            }
            if (f1 == 0 && f2 == 0 && f3 == 0) {
                ans -= 2;
            } else if (f1 == 0 || f2 == 0 || f3 == 0) {
                ans--;
            }
            i--;
        }
        return ans;
    }
};