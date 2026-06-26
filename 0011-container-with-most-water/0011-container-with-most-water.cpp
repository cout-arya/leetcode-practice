class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int ans=0;
        while (l < r) {
            int h = min(height[l], height[r]);
            int w = r - l;
            int area = h * w;
            if (height[l] > height[r]) {
                r--;
            } else {
                l++;
            }
            ans = max(ans, area);
        }
        return ans;
    }
};