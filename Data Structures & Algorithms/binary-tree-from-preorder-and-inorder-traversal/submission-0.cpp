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
    int preIndex=0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
            int l,int h){
        if(l>h){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int index;
        for(int i=l;i<=h;i++){
            if(inorder[i]==root->val){
                index = i;
                break;
            }
        }
        root->left = build(preorder,inorder,l,index-1);
        root->right = build(preorder,inorder,index+1,h);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,preorder.size()-1);
    }
};
