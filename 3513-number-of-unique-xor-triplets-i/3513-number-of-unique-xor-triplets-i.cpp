class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;
        int ans = 0;
        for (int num : nums) {
            ans |= num;
        }
        return ans + 1;
    }
};