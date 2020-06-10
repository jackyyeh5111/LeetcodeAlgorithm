
/*  This will cause time limited expired with O(n^2)
class Solution {
public:
    vector<bool> visited;
    vector<ListNode*> graph;

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        if(n==2) return {0,1};
        graph = vector<ListNode*>(n,0);
        map<int,ListNode*> tails;
        for(int i=0; i<n; ++i) {
            ListNode *node = new ListNode(0);
            tails[i] = node;
            graph[i] = node;
        }
        for (auto edge : edges) {
            tails[edge[0]]->next = new ListNode(edge[1]);
            tails[edge[1]]->next = new ListNode(edge[0]);
            tails[edge[0]] = tails[edge[0]]->next;
            tails[edge[1]] = tails[edge[1]]->next;
        }
        visited = vector<bool>(n, false);
        vector<int> candidates;
        for(int i=0; i<n; ++i){
            ListNode* node = graph[i];
            int count = 0;
            while(node->next) {
                count++;
                node=node->next;
            }
            if (count==1) candidates.push_back(i);
        }
        vector<int> longest;
        for (int leaf : candidates){
            vector<int> path = findLongest(leaf);
            if(path.size()>longest.size()) longest = path;
        }

        if(longest.size()%2==1) return {longest[longest.size()/2]};
        else return {longest[longest.size()/2],longest[longest.size()/2-1]};
    }

    vector<int> findLongest(int n) {
        visited[n] = true;
        ListNode* node = graph[n]->next;
        vector<int> max_path;
        while(node) {
            if(visited[node->val]) {
                node=node->next;
                continue;
            }
            vector<int> path = findLongest(node->val);
            if (path.size()>max_path.size()) max_path = path;
            node = node->next;
        }
        visited[n] = false;
        max_path.push_back(n);
        return max_path;
    }
};
*/

// O(N)
// Keep deleting leafs until 2 nodes remain
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for(auto e: edges){
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        vector<int> degree(n, 0);
        for(int i=0; i<n; i++) degree[i]=graph[i].size();
        for(int i=0, j, remain=n; i<n && remain>2; i++){
            vector<int> del; // nodes to delete
            for(j=0; j<n; j++){
                if(degree[j]==1) {
                    remain--;
                    del.push_back(j);
                    degree[j]=-1;
                }
            }
            for(auto k: del){ //delete this node and all connected edges
                for(auto neigh: graph[k]) degree[neigh]--;
            }
        }
        vector<int> res;
        for(int i=0; i<n; i++){
            if(degree[i]>=0) res.push_back(i);
        }
        return res;
    }
};
