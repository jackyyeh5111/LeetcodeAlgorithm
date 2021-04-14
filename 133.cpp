/***** Third Visit *****/
class Solution {
public:
    unordered_map<Node*,Node*> mp; //origin <-> copied
    Node* cloneGraph(Node* node)
    {
        if (!node) return 0;
        if (mp.count(node)) return mp[node];
        Node *copied = new Node(node->val);
        mp[node]=copied;
        for (auto n:node->neighbors)
            copied->neighbors.push_back(cloneGraph(n));
        return copied;
    }
};

/***** Second Visit *****/
/*
    dfs -> preorder traversal
    T:O(V+E)/S:O(V+E)
*/
class Solution {
public:
    unordered_map<Node*,Node*> m;
    Node* cloneGraph(Node* node) {
        if (!node) return 0;
        else if (m.count(node)!=0) return m[node];
        Node *new_node=new Node(node->val);
        m[node]=new_node;
        for (Node *v:node->neighbors) new_node->neighbors.push_back(cloneGraph(v));
        return new_node;
    }
};

/***** First Visit *****/
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
