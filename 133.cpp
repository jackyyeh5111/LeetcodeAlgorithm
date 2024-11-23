class Solution {
public:
    unordered_map<int, Node*> cloned;
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        cloneNode(node);
        dfs(node);
        return cloned[1];
    }
    Node* cloneNode(Node* node) {
        Node* c_node = new Node(node->val);
        cloned[node->val] = c_node;
        return c_node;
    }
    void dfs(Node* node) {
        if (!node) return;
        for (Node* neighbor_node : node->neighbors) {
            if (cloned.count(neighbor_node->val) == 0) {
                cloneNode(neighbor_node);
                dfs(neighbor_node);
            }
            cloned[node->val]->neighbors.push_back(cloned[neighbor_node->val]);
        }
    }
};