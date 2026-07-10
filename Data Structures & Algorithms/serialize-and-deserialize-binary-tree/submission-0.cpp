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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        dfs(root,res);
        int n=res.length();
        return res.substr(0,n-1);
    }

    void dfs(TreeNode* root, string& res){
        if(!root){
            res+="N,";
            return;
        }
        res+=(to_string(root->val)+",");
        dfs(root->left,res);
        dfs(root->right,res);
    }

    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals=split(data,',');
        int i=0;
        return df(vals,i);
    }

    TreeNode* df(vector<string>& data, int& i){
        if(data[i]=="N"){
            i++;
            return nullptr;
        }
        TreeNode* node=new TreeNode(stoi(data[i]));
        i++;
        node->left = df(data,i);
        node->right=df(data,i);
        return node;
    }
};
