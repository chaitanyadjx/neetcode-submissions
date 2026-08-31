class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashSet;
        int left = 0;
        int maxlength = 0;

        for(int i = 0; i < s.length(); i++){
            while(hashSet.find(s[i]) != hashSet.end()){
                hashSet.erase(s[left]);
                left++;
            }
            hashSet.insert(s[i]);
            maxlength = max(maxlength, i - left + 1);
        }
        return maxlength;
    }
};
