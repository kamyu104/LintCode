// Time:  O(|V| + |E|)
// Space: O(|E|)

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
// BFS
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
private:
    void findDependencyBFS(
                           DirectedGraphNode* node,
                           unordered_set<DirectedGraphNode *> &nodes,
                           unordered_map<DirectedGraphNode *, int> &ancestors) {
        if (nodes.insert(node).second) {
            queue<DirectedGraphNode *> scheduled;
            scheduled.emplace(node);
            while (!scheduled.empty()) {
                DirectedGraphNode *node = scheduled.front();
                scheduled.pop();

                // Update in degree of neighbors.
                for (auto& neighbor : node->neighbors) {
                    ++ancestors[neighbor];
                    if (nodes.insert(neighbor).second) {
                        scheduled.emplace(neighbor);
                    }
                }
            }
        }
    }

    void topSortBFS(
                    vector<DirectedGraphNode*>& graph,
                    unordered_map<DirectedGraphNode *, int> &ancestors,
                    vector<DirectedGraphNode *> &output) {
        // Find the nodes with 0 in degree.
        queue<DirectedGraphNode *> scheduled;
        for (auto& node : graph) {
            if (ancestors[node] == 0) {
                scheduled.emplace(node);
            }
        }

        while (!scheduled.empty()) {
            DirectedGraphNode *node = scheduled.front();
            output.emplace_back(node);
            scheduled.pop();

            // Update in degree of neighbors.
            for (auto& neighbor : node->neighbors) {
                --ancestors[neighbor];
                if (ancestors[neighbor] == 0) {
                    scheduled.emplace(neighbor);
                }
            }
        }
    }
public:

    // @param graph: A list of Directed graph node
    // @return: Any topological order for the given graph.
    //
    vector<DirectedGraphNode *> topSort(vector<DirectedGraphNode*> graph) {
        vector<DirectedGraphNode *> output;

        // Find ancestors of each node by DFS
        unordered_set<DirectedGraphNode *> nodes;
        unordered_map<DirectedGraphNode *, int> ancestors;
        for (auto& node :graph) {
            findDependencyBFS(node, nodes, ancestors);
        }

        // Output topological order by BFS
        topSortBFS(graph, ancestors, output);

        return output;
    }
};

// DFS
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
private:
    void findDependencyDFS(
                           DirectedGraphNode* node,
                           unordered_set<DirectedGraphNode *> &nodes,
                           unordered_map<DirectedGraphNode *, vector<DirectedGraphNode *>> &ancestors) {
        if (nodes.insert(node).second) {
            for (auto& neighbor : node->neighbors) {
                ancestors[neighbor].emplace_back(node);
                findDependencyDFS(neighbor, nodes, ancestors);
            }
        }
    }

    void topSortDFS(
                    DirectedGraphNode *node,
                    unordered_map<DirectedGraphNode *, vector<DirectedGraphNode *>> &ancestors,
                    unordered_set<DirectedGraphNode *> &scheduled,
                    vector<DirectedGraphNode *> &output) {
        if (scheduled.insert(node).second) {
            for (auto& ancestor: ancestors[node]) {
                topSortDFS(ancestor, ancestors, scheduled, output);
            }
            output.emplace_back(node);
        }
    }
public:

    // @param graph: A list of Directed graph node
    // @return: Any topological order for the given graph.
    //
    vector<DirectedGraphNode *> topSort(vector<DirectedGraphNode*> graph) {
        vector<DirectedGraphNode *> output;

        // Find ancestors of each node by DFS
        unordered_set<DirectedGraphNode *> nodes;
        unordered_map<DirectedGraphNode *, vector<DirectedGraphNode *>> ancestors;
        for (auto& node :graph) {
            findDependencyDFS(node, nodes, ancestors);
        }

        // Output topological order by DFS
        unordered_set<DirectedGraphNode *> scheduled;
        for (auto& node : graph) {
            topSortDFS(node, ancestors, scheduled, output);
        }

        return output;
    }
};
