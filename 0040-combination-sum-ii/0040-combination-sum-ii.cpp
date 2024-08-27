class Solution {
public:
    void findCombinations(int index, int target, vector<int>& candidates, vector<int>& currentCombination, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(currentCombination);
        return;
    }

    for (int i = index; i < candidates.size(); i++) {
        if (i > index && candidates[i] == candidates[i - 1])
            continue; // Skip duplicates

        if (candidates[i] > target)
            break; // No point in continuing if the current number is greater than the remaining target

        currentCombination.push_back(candidates[i]);
        findCombinations(i + 1, target - candidates[i], candidates, currentCombination, result);
        currentCombination.pop_back(); // Backtrack
    }
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> currentCombination;
    findCombinations(0, target, candidates, currentCombination, result);
    return result;
    }
};