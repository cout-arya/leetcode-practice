class Solution {
public:
    int binarySearch(vector<int>& num, int l, int r, int target) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (num[mid] == target) {
                return mid;
            } else if (num[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            int rem = target - numbers[i];
            int ans = binarySearch(numbers, i + 1, n - 1, rem);
            if (ans != -1) {
                return {i + 1, ans + 1};
            }
        }
        return {};
    }
};