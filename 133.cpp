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

//BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        Node* copy = new Node(node -> val, {});
        copies[node] = copy;
        queue<Node*> todo;
        todo.push(node);
        while (!todo.empty()) {
            Node* cur = todo.front();
            todo.pop();
            for (Node* neighbor : cur -> neighbors) {
                if (copies.find(neighbor) == copies.end()) {
                    copies[neighbor] = new Node(neighbor -> val, {});
                    todo.push(neighbor);
                }
                copies[cur] -> neighbors.push_back(copies[neighbor]);
            }
        }
        return copy;
    }
private:
    unordered_map<Node*, Node*> copies;
};

// DFS
class Solution {
public:
    unordered_map<int,Node*> table;
    Node* cloneGraph(Node* node)
    {
        if (!node) return 0;
        else if (node->neighbors.size()==0) return new Node(node->val);
        int val=node->val;
        if(table.find(val)!=table.end()) return table[val];
        Node* newNode = new Node(val);
        table[val]=newNode;
        for(Node* v:node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(v));
        }
        return newNode;
    }
};
