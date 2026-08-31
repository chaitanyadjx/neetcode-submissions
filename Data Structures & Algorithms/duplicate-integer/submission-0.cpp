class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(int x: nums){
            hash[x]++;
        }
        for(auto x: hash){
            if(x.second > 1) return true;
        }
        return false;
    }
};
