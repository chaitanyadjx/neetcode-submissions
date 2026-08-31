class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_set<int> seen(nums.begin(), nums.end());
        int maxlen = 1;
        
        for (int num : nums) {
            if (seen.find(num - 1) == seen.end()) {
                int currentNum = num;
                int currentStreak = 1;
                
                while (seen.find(currentNum + 1) != seen.end()) {
                    currentNum++;
                    currentStreak++;
                }
                
                maxlen = max(maxlen, currentStreak);
            }
        }
        
        return maxlen;
    }
};