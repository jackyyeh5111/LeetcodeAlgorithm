/*
    More elegant dfs approach.
*/
class Solution2 {
public:
    unordered_map<int, Node*> cloned;
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        if (cloned.find(node->val) != cloned.end())
            return cloned[node->val];
        
        // dfs
        cloned[node->val] = new Node(node->val);
        for (Node* neighbor : node->neighbors) {
            if (cloned.find(neighbor->val) == cloned.end()) {
                cloned[neighbor->val] = cloneGraph(neighbor);
            }
            cloned[node->val]->neighbors.push_back(cloned[neighbor->val]);
        }
        return cloned[node->val];
    }
};


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
    unordered_map<int, Node*> cloned;
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        dfs(node);
        return cloned[1];
    }
    
    void dfs(Node* node) {
        if (cloned.find(node->val) != cloned.end())
            return;
        
        Node* new_node = new Node(node->val);
        cloned[node->val] = new_node;
        for (Node* neighbor : node->neighbors) {
            dfs(neighbor);
            new_node->neighbors.push_back(cloned[neighbor->val]);
        }
    }
};



