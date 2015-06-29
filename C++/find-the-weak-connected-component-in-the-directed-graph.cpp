// Time:  O(nlogn)
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
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        // Sort nodes by its index. Time: O(nlogn)
        sort(nodes.begin(), nodes.end(),
             [](const DirectedGraphNode* a, const DirectedGraphNode* b) {
                return a->label < b->label;
             });
        // The disjoint-set.
        unordered_map<int, int> set;
        // Initialize the disjoint-set.
        for (const auto& node : nodes) {
            set[node->label] = node->label;
        }

        // Union-Find each edge.
        for (const auto& node : nodes) {
            for (const auto& neighbor : node->neighbors) {
                union_set(&set, node->label, neighbor->label);
            }
        }

        // Group each component.
        unordered_map<int, vector<int>> group;
        for (const auto& node : nodes) {
            group[find_set(node->label, &set)].emplace_back(node->label);
        }

        // Sort elements in each group.
        vector<vector<int>> result;
        for (auto& kvp : group) {
            result.emplace_back(move(kvp.second));
        }
        return result;
    }

    int find_set(int x, unordered_map<int, int> *set) {
       if ((*set)[x] != x) {
           (*set)[x] = find_set((*set)[x], set);  // path compression.
       }
       return (*set)[x];
    }

    void union_set(unordered_map<int, int> *set, int x, int y) {
        int x_root = find_set(x, set), y_root = find_set(y, set);
        (*set)[min(x_root, y_root)] = max(x_root, y_root);
    }
};
