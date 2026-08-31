class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> freq;
        
        for(int num: nums) {
            freq[num]++;
        }
        
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        
        for(auto& pair : freq) {
            buckets[pair.second].push_back(pair.first);
        }
        
        for(int i = n; i >= 0 && result.size() < k; i--) {
            if(!buckets[i].empty()) {
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        
        if(result.size() > k) {
            result.resize(k);
        }
        
        return result;
    }
};