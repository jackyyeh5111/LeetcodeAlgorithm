class ThroneInheritance {
public:
    struct Node {
        string name="";
        vector<Node*> children;
        Node(string name=""){this->name=name;}
    };

    unordered_map<string,Node*> table;
    Node *root=0;
    ThroneInheritance(string kingName) {
        Node *node=new Node(kingName);
        root=node;
        table[kingName]=node; // cur, parent
    }

    void birth(string parentName, string childName) {
        Node *node=new Node(childName);
        table[parentName]->children.push_back(node);
        table[childName]=node;
    }

    void death(string name) {
        table[name]->name="";;
        table.erase(name);
    }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(root,ans);
        return ans;
    }

    void dfs(Node *root, vector<string> &ans)
    {
        if (!root) return;
        if (root->name!="") ans.push_back(root->name);
        for (auto &child:root->children)
            dfs(child,ans);
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
