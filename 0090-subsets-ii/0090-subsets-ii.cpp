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
        int idx=i+1;
        int n=nums.size();
        while(idx<n && nums[idx]==nums[idx-1]){
            idx++;
        }
        solve(nums, idx, ans, curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end()); // sorting
        solve(nums, 0, ans, curr);
        return ans;
    }
};