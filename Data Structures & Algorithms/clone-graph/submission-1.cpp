/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> on;
        return dfs(node,on);
    }

    Node* dfs(Node* node,unordered_map<Node*,Node*>& on){
        if(node==nullptr)
            return nullptr;
        if(on.count(node)){
            return on[node];
        }

        Node* copy=new Node(node->val);
        on[node]=copy;

        for(Node* n:node->neighbors){
            copy->neighbors.push_back(dfs(n,on));
        }
        return copy;
    }
};
