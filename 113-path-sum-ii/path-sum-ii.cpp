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
    vector<vector<int>>ans;
    void helper(TreeNode* root,int sum, int targetSum, vector<int>d){
        if(!root) return;

        if(root){
            sum+=root->val;
            d.push_back(root->val);
        }
        if(!root->left && !root->right){
            if(sum==targetSum){
                ans.push_back(d);
                d.pop_back();
            }
        }
        else{
            helper(root->left,sum,targetSum,d);
            helper(root->right,sum,targetSum,d);
        }
    }



    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>d;
        helper(root,0,targetSum,d);
        return ans;
    }
};