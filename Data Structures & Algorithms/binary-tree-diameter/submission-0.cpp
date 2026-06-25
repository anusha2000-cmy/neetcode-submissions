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
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        int depth = height(root,max);
        return max;
    }

    int height(TreeNode* root,int& max){
        if(root==nullptr){
            return 0;
        }
        int left=height(root->left,max);
        int right=height(root->right,max);
        int dia=left+right;
        if(dia>max){
            max=dia;
        }
        return 1+(left>right?left:right);
    }
};
