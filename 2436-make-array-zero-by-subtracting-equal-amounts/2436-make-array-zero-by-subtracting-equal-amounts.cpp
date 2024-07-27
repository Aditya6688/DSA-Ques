class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> uniquePositiveNums;
        
        for (int num : nums) {
            if (num > 0) {
                uniquePositiveNums.insert(num);
            }
        }
        
        return uniquePositiveNums.size();
    }
};