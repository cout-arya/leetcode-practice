class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
            }
            if (nums[i] < mini) {
                mini = nums[i];
            }
        }
        while (mini != 0) {
            int rem = maxi % mini;
            maxi = mini;
            mini = rem;
        }
        return maxi;
    }
};