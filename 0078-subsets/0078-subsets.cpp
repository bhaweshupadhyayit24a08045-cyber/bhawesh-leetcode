class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int>& curr){
        //base case
        if(i==nums.size()) {
            ans.push_back(curr);
            return;
        }
        //selecting branch
        curr.push_back(nums[i]);
        solve(nums, i+1, ans, curr);
        curr.pop_back(); // backtracking

        //reject branch
        solve(nums, i+1, ans, curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums, 0, ans, curr);
        return ans;
    }
};