class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int n:nums){
            mp[n]++;
        }
        int i=k;
        while(true){
            if(mp.count(i)){
                i+=k;
            }else{
                return i;
                break;
            }
        }
        return 0;
    }
};