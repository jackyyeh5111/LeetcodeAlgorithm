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
    if (!node) return nullptr;

    unordered_map<int, Node*> cloned;
    queue<Node*> que;
    que.push(node);
    cloned[node->val] = new Node(node->val);

    while (!que.empty()) {
      Node* cur = que.front();
      que.pop();

      for (auto nb : cur->neighbors) {
        if (cloned.find(nb->val) == cloned.end()) {
          cloned[nb->val] = new Node(nb->val);
          que.push(nb);
        }
        cloned[cur->val]->neighbors.push_back(cloned[nb->val]);
      }
    }
    return cloned[1];
  }
};
