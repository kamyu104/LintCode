// Time:  O(n)
// Space: O(n)

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        unordered_set<DirectedGraphNode *> visited_node;
        visited_node.insert(s);
        return BFS(s, t, visited_node);
    }
    bool BFS( DirectedGraphNode* s, DirectedGraphNode* t,
             unordered_set<DirectedGraphNode *> &visited_node) {
        queue<DirectedGraphNode *> q;
        q.push(s);
        while (!q.empty()) {
            s = q.front();
            q.pop();
            
            if (s == t) {
                return true;
            }
            
            // Add neighbors which are not visited into the queue
            for (auto& node: s->neighbors) {
                if (visited_node.insert(node).second) {
                    q.push(node);
                }
            }
        }
        
        return false;
    }
    
};


// DFS
class Solution2 {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        unordered_set<DirectedGraphNode *> visited_node;
        visited_node.insert(s);
        return DFS(s, t, visited_node);
    }
    bool DFS( DirectedGraphNode* s, DirectedGraphNode* t,
             unordered_set<DirectedGraphNode *> &visited_node) {
        if (s == t) {
            return true;
        }
        
        // Search neighbors which are not visted
        for (auto& node: s->neighbors) {
            if (visited_node.insert(node).second) {
                if (DFS(node, t, visited_node)) {
                    return true;
                }
                //visited_node.erase(node);
            }
        }
        return false;
    }
    
};


