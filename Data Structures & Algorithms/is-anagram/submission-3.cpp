class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash1;
        unordered_map<char, int> hash2;
        int c1, c2;
        c1 = c2 = 0;
        for(auto x: s){
            hash1[x]++;
            c1++;
        }
        for(auto y: t){
            hash2[y]++;
            c2++;
        }
        if(c1 != c2) return false;
        for(auto x: s){
            if(hash1[x] != hash2[x]){
                return false;
            } 
        }
        return true;
        

    }
};
