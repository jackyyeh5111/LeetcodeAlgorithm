/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
import java.util.*;
class Solution {
    public List<Integer> postorder(Node root) {
        List<Integer> result = new ArrayList<Integer>();
        if (root == null) return result;

        Stack<Node> nodeStack = new Stack<Node>();
        nodeStack.push(root);
        while (!nodeStack.empty()) {
            Node node = nodeStack.peek();
            if (node.children.size() == 0) {
                result.add(node.val);
                nodeStack.pop();
            } else {
                for (int i=node.children.size()-1; i>=0; i--) {
                    nodeStack.push(nodeStack.get(i));
                }
                node.children.clear();
            }
        }

        return result;
    }
}
