class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> freq; 
        
        for(string s: strs) {
            vector<int> count(26, 0);
            for(char c: s) {
                count[c - 'a']++;
            }
            
            string key = "";
            for(int i = 0; i < 26; i++) {
                key += '#' + to_string(count[i]);
            }
            
            freq[key].push_back(s);
        }
        
        for(auto& pair: freq) {
            res.push_back(pair.second);
        }
        
        return res;
    }
};