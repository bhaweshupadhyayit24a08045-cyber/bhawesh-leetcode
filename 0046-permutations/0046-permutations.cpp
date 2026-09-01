class Solution {
public:
    vector<int> curr;
    vector<vector<int>> ans;

    bool isValid(vector<int> curr){
        unordered_map<int, int> m;
        for(auto it: curr){
            m[it]++;
        }
        for(auto it: m){
            if(it.second>1) return false;
        }
        return true;
    }
    void solve(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans){
        //base case
        if(curr.size()==nums.size()){
            if(isValid(curr)) ans.push_back(curr);
            return;
        }

        for(int i=0; i<nums.size();i++){
        curr.push_back(nums[i]);
        solve(nums, curr, ans);
        curr.pop_back(); // undo(backtracking)
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, curr, ans);
        return ans;
    }
};