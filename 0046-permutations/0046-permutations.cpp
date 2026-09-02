class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int>& curr, int i){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        } 

        unordered_map<int, int> m;
        for(auto it: curr){
            m[it]++;
        }

        for(int i=0; i<nums.size(); i++){
            //valid
            if(m.find(nums[i]) == m.end()) {
                curr.push_back(nums[i]);
                solve(nums, curr, i);
                curr.pop_back(); // backtrack
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<int> curr;
    int i=0;
    solve(nums, curr, i);
    return ans;   
    }
};