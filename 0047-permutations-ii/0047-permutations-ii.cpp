class Solution {
public:
    vector<vector<int>> ans;
    // bool isValid(vector<int>& nums, vector<int> curr){
    void solve(vector<int>& nums, vector<int>& curr, unordered_map<int, int>& m) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (auto& it : m) {
            if (it.second >= 1) {
                curr.push_back(it.first);
                it.second--;
                solve(nums, curr, m);
                it.second++;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    // sort(nums.begin()=nums.end());
    unordered_map<int, int> m;
    for (auto it : nums) {
        m[it]++;
    }
    vector<int> curr;
    solve(nums, curr, m);
    return ans;
    }
};