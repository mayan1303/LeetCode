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

    bool isValid(TreeNode* root, TreeNode* lnode, TreeNode* rnode){
        if(root==NULL) return true;
        
        if(lnode!=NULL && lnode->val>=root->val) return false;

        if(rnode!=NULL && rnode->val<=root->val) return false;

        return isValid(root->left,lnode,root) &&
                isValid(root->right, root, rnode);

    }


    bool isValidBST(TreeNode* root) {
        return isValid(root, NULL, NULL);
    }
};