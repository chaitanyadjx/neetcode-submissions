class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        for(int i = 0; i < nums.size(); i++){
            int difference = target - nums[i];
            if(hashTable.find(difference) != hashTable.end()){
                return {hashTable[difference], i};
            }
            hashTable[nums[i]] = i;
        }
        return {-1, -1};
    }
};
