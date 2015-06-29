// Time:  O(n)
// Space: O(n)

/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        vector<vector<int>> components;
        queue<UndirectedGraphNode*> q;
        unordered_set<UndirectedGraphNode*> visited;

        for (const auto& node : nodes) {
            if (visited.find(node) == visited.end()) {
                visited.emplace(node);
                q.emplace(node);

                vector<int> component;
                while (!q.empty()) {
                    auto node = q.front();
                    q.pop();
                    component.emplace_back(node->label);
                    for (const auto& n : node->neighbors) {
                        if (visited.find(n) == visited.end()) {
                            visited.emplace(n);
                            q.emplace(n);
                        }
                    }
                }
                // Sort component.
                sort(component.begin(), component.end());
                components.emplace_back(move(component));
            }
        }

        return components;
    }
};
