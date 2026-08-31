class Solution {
public:
    string encode(vector<string>& strs) {
        string res = "";
        for(string str: strs) {
            res += to_string(str.size()) + "#" + str;
        }
        return res;   
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        
        while(i < s.size()) {
            int delimiterPos = s.find('#', i);
            
            int len = stoi(s.substr(i, delimiterPos - i));
            
            i = delimiterPos + 1;
            
            res.push_back(s.substr(i, len));
            
            i += len;
        }
        
        return res;
    }
};