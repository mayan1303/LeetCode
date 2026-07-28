class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(vector<int>& candidates, int index, int target) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (index == candidates.size() || target < 0)
            return;

        
        if (candidates[index] <= target) {
            curr.push_back(candidates[index]);
            solve(candidates, index, target - candidates[index]);
            curr.pop_back();
        }

        
        solve(candidates, index + 1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, 0, target);
        return ans;
    }
};