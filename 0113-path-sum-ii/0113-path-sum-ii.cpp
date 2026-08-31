/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(vector<int>&temp,vector<vector<int>>&res,TreeNode* root,int targetSum,int &currSum){
        if(root == nullptr) return;
        temp.push_back(root->val);
        currSum += root->val;
        if(root->left == nullptr && root->right == nullptr){
            if(currSum == targetSum){
                res.push_back(temp);
            }
                currSum -= root->val;
                temp.pop_back();
                return;
        }
        solve(temp,res,root->left,targetSum,currSum);
        solve(temp,res,root->right,targetSum,currSum);
        currSum -= root->val;
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>temp;
        int currSum = 0;
        solve(temp,res,root,targetSum,currSum);
        return res;
    }
};