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
    int kthSmallest(TreeNode* root, int k) {
        int small=0;
        int count=0;
        find(root,count,k,small);
        return small;
    }

    void find(TreeNode* root,int& count,int k,int& small){
        if(!root)
            return;
        find(root->left,count,k,small);
        count++;
        if(count==k){
            small=root->val;
            return;
        }
        find(root->right,count,k,small);
    }
};
