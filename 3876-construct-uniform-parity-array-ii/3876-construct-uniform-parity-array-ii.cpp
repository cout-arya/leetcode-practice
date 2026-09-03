class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool flag = true;
        int n = nums1.size();
        for (int i = 1; i < n; i++) {
            if ((nums1[i] % 2) != (nums1[0] % 2)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
        int mn = *min_element(nums1.begin(), nums1.end());
        return ((mn % 2) == 1);
    }
};