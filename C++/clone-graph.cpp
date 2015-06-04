// Time:  O(|V| + |E|)
// Space: O(|V|)

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return nullptr;
        }
        unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copied;
        copied[node] = new UndirectedGraphNode(node->label);
        queue<const UndirectedGraphNode *> q;
        q.emplace(node);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            for (const auto& n : node->neighbors) {
                if (copied.find(n) == copied.end()) {
                    copied[n] = new UndirectedGraphNode(n->label);
                    q.emplace(n);
                }

                copied[node]->neighbors.emplace_back(copied[n]);
            }
        }

        return copied[node];
    }
};
