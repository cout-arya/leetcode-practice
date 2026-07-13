class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string s = "123456789";
        string l = to_string(low);
        string h = to_string(high);
        for (int i = l.size(); i <= h.size(); i++) {
            for (int j = 0; j + i <= 9; j++) {
                int num = stoi(s.substr(j, i));
                if (num >= low && num <= high) {
                    res.push_back(num);
                }
            }
        }
        return res;
    }
};