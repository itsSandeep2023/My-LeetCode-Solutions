/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void pot(Node* r, vector<int>& ans) {
        if (!r)
            return;

        for (auto child : r->children)
            pot(child, ans);

        ans.push_back(r->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        pot(root, ans);
        return ans;
    }
};