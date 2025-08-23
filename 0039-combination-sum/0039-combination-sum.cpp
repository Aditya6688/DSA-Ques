class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;

    void func(vector<int>& candidates, int target, int idx){
        if(target == 0){
            res.push_back(ans);
            return;
        }

        if(idx>=candidates.size() || target < 0) return;

        ans.push_back(candidates[idx]);
        func(candidates, target-candidates[idx],idx);
        ans.pop_back();
        func(candidates, target,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        func(candidates,target,0);
        return res;
    }
};